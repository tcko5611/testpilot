#include "OSGCamera.hpp"

#include <osg/Camera>
#include <osg/Node>

#include <osgEarthUtil/LogarithmicDepthBuffer>

#include <QDebug>

namespace osgQtQuick {
enum DirtyFlag { FieldOfView = 1 << 0, ClearColor = 1 << 1, LogDepthBuffer = 1 << 4 };

struct OSGCamera::Hidden : public QObject {
    Q_OBJECT

private:
    OSGCamera * const self;

    osg::ref_ptr<osg::Camera> camera;

public:
    // Camera vertical field of view in degrees
    // fov depends on the scenery space (probably distance)
    // here are some value: 75°, 60°, 45° many gamers use
    // x-plane uses 45° for 4:3 and 60° for 16:9/16:10
    // flightgear uses 55° / 70°
    qreal  fieldOfView;

    QColor clearColor;

    bool   logDepthBufferEnabled;

    osgEarth::Util::LogarithmicDepthBuffer *logDepthBuffer;

public:
    Hidden(OSGCamera *self) : QObject(self), self(self), fieldOfView(90), clearColor(0, 0, 0, 255), logDepthBufferEnabled(false)
    {
        logDepthBuffer = NULL;
    }

    ~Hidden()
    {
        if (logDepthBuffer) {
            logDepthBuffer->uninstall(camera);
            delete logDepthBuffer;
            logDepthBuffer = NULL;
        }
    }

    osg::Node *createNode()
    {
        camera = new osg::Camera();

        camera->setClearColor(osg::Vec4(clearColor.redF(), clearColor.greenF(), clearColor.blueF(), clearColor.alphaF()));

        osg::StateSet *stateset = camera->getOrCreateStateSet();
        stateset->setGlobalDefaults();

        return camera;
    }

    void updateClearColor()
    {
        if (!camera.valid()) {
            qWarning() << "OSGCamera::updateClearColor - invalid camera";
            return;
        }
        // qDebug() << "OSGCamera::updateClearColor" << clearColor;
        camera->setClearColor(osg::Vec4(clearColor.redF(), clearColor.greenF(), clearColor.blueF(), clearColor.alphaF()));
    }

    void updateFieldOfView()
    {
        if (!camera.valid()) {
            qWarning() << "OSGCamera::updateFieldOfView - invalid camera";
            return;
        }

        // qDebug() << "OSGCamera::updateFieldOfView" << fieldOfView;

        double fovy, ar, zn, zf;
        camera->getProjectionMatrixAsPerspective(fovy, ar, zn, zf);
        fovy = fieldOfView;
        camera->setProjectionMatrixAsPerspective(fovy, ar, zn, zf);
    }

    void updateAspectRatio()
    {
        if (!camera.valid()) {
            qWarning() << "OSGCamera::updateAspectRatio - invalid camera";
            return;
        }
        osg::Viewport *viewport = camera->getViewport();
        if (!viewport) {
            qWarning() << "OSGCamera::updateAspectRatio - no viewport" << viewport;
            return;
        }

        double aspectRatio = static_cast<double>(viewport->width()) / static_cast<double>(viewport->height());

        // qDebug() << "OSGCamera::updateAspectRatio" << aspectRatio;

        double fovy, ar, zn, zf;
        camera->getProjectionMatrixAsPerspective(fovy, ar, zn, zf);
        ar = aspectRatio;
        camera->setProjectionMatrixAsPerspective(fovy, ar, zn, zf);
    }

    void updateLogDepthBuffer()
    {
        if (!camera.valid()) {
            qWarning() << "OSGCamera::updateLogDepthBuffer - invalid camera";
            return;
        }
        // qDebug() << "OSGCamera::updateLogDepthBuffer" << logDepthBufferEnabled;

        // install log depth buffer if requested
        if (logDepthBufferEnabled && !logDepthBuffer) {
            // qDebug() << "OSGCamera::updateLogDepthBuffer - installing logarithmic depth buffer";
            logDepthBuffer = new osgEarth::Util::LogarithmicDepthBuffer();
            logDepthBuffer->setUseFragDepth(true);
            logDepthBuffer->install(camera);
        } else if (!logDepthBufferEnabled && logDepthBuffer) {
            // qDebug() << "OSGCamera::updateLogDepthBuffer - uninstalling logarithmic depth buffer";
            logDepthBuffer->uninstall(camera);
            delete logDepthBuffer;
            logDepthBuffer = NULL;
        }
    }

    void setGraphicsContext(osg::GraphicsContext *gc)
    {
        if (!camera.valid()) {
            qWarning() << "OSGCamera::setGraphicsContext - invalid camera";
            return;
        }

        // qDebug() << "OSGCamera::setGraphicsContext" << gc;

        camera->setGraphicsContext(gc);
        camera->setViewport(0, 0, gc->getTraits()->width, gc->getTraits()->height);

        double aspectRatio = static_cast<double>(gc->getTraits()->width) / static_cast<double>(gc->getTraits()->height);

        camera->setProjectionMatrixAsPerspective(fieldOfView, aspectRatio, 1.0f, 10000.0f);

        double fovy, ar, zn, zf;
        camera->getProjectionMatrixAsPerspective(fovy, ar, zn, zf);

        // FIXME this is needed for PFD + Terrain (because of "user" mode)
        // updatePosition();
    }
};

/* class OSGCamera */

OSGCamera::OSGCamera(QObject *parent) : Inherited(parent), h(new Hidden(this))
{}

OSGCamera::~OSGCamera()
{
    delete h;
}

QColor OSGCamera::clearColor() const
{
    return h->clearColor;
}

void OSGCamera::setClearColor(const QColor &color)
{
    if (h->clearColor != color) {
        h->clearColor = color;
        emit clearColorChanged(color);
    }
}

qreal OSGCamera::fieldOfView() const
{
    return h->fieldOfView;
}

void OSGCamera::setFieldOfView(qreal arg)
{
    if (h->fieldOfView != arg) {
        h->fieldOfView = arg;
        setDirty(FieldOfView);
        emit fieldOfViewChanged(fieldOfView());
    }
}

bool OSGCamera::logarithmicDepthBuffer() const
{
    return h->logDepthBufferEnabled;
}

void OSGCamera::setLogarithmicDepthBuffer(bool enabled)
{
    if (h->logDepthBufferEnabled != enabled) {
        h->logDepthBufferEnabled = enabled;
        setDirty(LogDepthBuffer);
        emit logarithmicDepthBufferChanged(logarithmicDepthBuffer());
    }
}

osg::Node *OSGCamera::createNode()
{
    return h->createNode();
}

void OSGCamera::updateNode()
{
    Inherited::updateNode();

    if (isDirty(ClearColor)) {
        h->updateClearColor();
    }
    if (isDirty(FieldOfView)) {
        h->updateFieldOfView();
    }
    if (isDirty(LogDepthBuffer)) {
        h->updateLogDepthBuffer();
    }
}

osg::Camera *OSGCamera::asCamera() const
{
    // BAD introduce templating
    return (osg::Camera *)node();
}

void OSGCamera::setGraphicsContext(osg::GraphicsContext *gc)
{
    h->setGraphicsContext(gc);
}
} // namespace osgQtQuick

#include "OSGCamera.moc"
