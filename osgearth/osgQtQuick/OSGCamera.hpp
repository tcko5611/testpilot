#ifndef _H_OSGQTQUICK_OSGCAMERA_H_
#define _H_OSGQTQUICK_OSGCAMERA_H_

#include "Export.hpp"
#include "OSGNode.hpp"

#include <QObject>
#include <QColor>

namespace osg {
class Camera;
class GraphicsContext;
}

namespace osgQtQuick {
class OSGQTQUICK_EXPORT OSGCamera : public OSGNode {
    Q_OBJECT Q_PROPERTY(QColor clearColor READ clearColor WRITE setClearColor NOTIFY clearColorChanged)
    Q_PROPERTY(qreal fieldOfView READ fieldOfView WRITE setFieldOfView NOTIFY fieldOfViewChanged)
    Q_PROPERTY(bool logarithmicDepthBuffer READ logarithmicDepthBuffer WRITE setLogarithmicDepthBuffer NOTIFY logarithmicDepthBufferChanged)

    typedef OSGNode Inherited;

    friend class OSGViewport;

public:
    explicit OSGCamera(QObject *parent = 0);
    virtual ~OSGCamera();

    QColor clearColor() const;
    void setClearColor(const QColor &color);

    qreal fieldOfView() const;
    void setFieldOfView(qreal arg);

    bool logarithmicDepthBuffer() const;
    void setLogarithmicDepthBuffer(bool enabled);

signals:
    void clearColorChanged(const QColor &color);
    void fieldOfViewChanged(qreal arg);
    void logarithmicDepthBufferChanged(bool enabled);

protected:
    virtual osg::Node *createNode();
    virtual void updateNode();

private:
    struct Hidden;
    Hidden *const h;

    osg::Camera *asCamera() const;
    void setGraphicsContext(osg::GraphicsContext *gc);
};
} // namespace osgQtQuick

#endif // _H_OSGQTQUICK_OSGCAMERA_H_
