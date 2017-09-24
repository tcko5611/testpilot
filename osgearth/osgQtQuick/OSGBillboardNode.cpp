#include "OSGBillboardNode.hpp"

#include <osg/Depth>
#include <osg/Texture2D>
#include <osg/ImageSequence>

#include <osgDB/ReadFile>

#include <QDebug>

namespace osgQtQuick {
// NOTE : these flags should not overlap with OSGGroup flags!!!
// TODO : find a better way...
enum DirtyFlag {};

struct OSGBillboardNode::Hidden : public QObject {
    Q_OBJECT

private:
    OSGBillboardNode * const self;

    osg::ref_ptr<osg::Camera> camera;

public:
    Hidden(OSGBillboardNode *self) : QObject(self), self(self)
    {}

    osg::Node *createNode()
    {
        camera = new osg::Camera;
        camera->setClearMask(0);
        camera->setCullingActive(false);
        camera->setAllowEventFocus(false);
        camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
        camera->setRenderOrder(osg::Camera::POST_RENDER);
        camera->setProjectionMatrix(osg::Matrix::ortho2D(0.0, 1.0, 0.0, 1.0));

        osg::StateSet *ss = camera->getOrCreateStateSet();
        ss->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
        ss->setAttributeAndModes(new osg::Depth(osg::Depth::LEQUAL, 1.0, 1.0));

        return camera;
    }
};

/* class OSGBillboardNode */

OSGBillboardNode::OSGBillboardNode(QObject *parent) : Inherited(parent), h(new Hidden(this))
{}

OSGBillboardNode::~OSGBillboardNode()
{
    delete h;
}

osg::Node *OSGBillboardNode::createNode()
{
    return h->createNode();
}

void OSGBillboardNode::updateNode()
{
    Inherited::updateNode();
}
} // namespace osgQtQuick

#include "OSGBillboardNode.moc"
