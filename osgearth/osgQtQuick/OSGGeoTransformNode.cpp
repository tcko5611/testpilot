#include "OSGGeoTransformNode.hpp"

#include "utils/utility.h"

#include <osg/ComputeBoundsVisitor>

#include <osgEarth/GeoTransform>
#include <osgEarth/MapNode>
#include <osgEarth/GeoData>

#include <QDebug>

namespace osgQtQuick {
// NOTE : these flags should not overlap with OSGGroup flags!!!
// TODO : find a better way...
enum DirtyFlag { Scene = 1 << 10, Position = 1 << 11, Clamp = 1 << 12 };

struct OSGGeoTransformNode::Hidden : public QObject {
    Q_OBJECT

private:
    OSGGeoTransformNode * const self;

    osg::ref_ptr<osgEarth::GeoTransform> transform;

public:
    OSGNode   *sceneNode;

    float     offset;

    bool      clampToTerrain;
    bool      intoTerrain;

    QVector3D position;

    Hidden(OSGGeoTransformNode *self) : QObject(self), self(self), sceneNode(NULL), offset(-1.0), clampToTerrain(false), intoTerrain(false)
    {}

    osg::Node *createNode()
    {
        transform = new osgEarth::GeoTransform();
        transform->setAutoRecomputeHeights(true);
        return transform;
    }

    bool acceptSceneNode(OSGNode *node)
    {
        // qDebug() << "OSGGeoTransformNode::acceptSceneNode" << node;
        if (sceneNode == node) {
            return false;
        }

        if (sceneNode) {
            disconnect(sceneNode);
        }

        sceneNode = node;

        if (sceneNode) {
            connect(sceneNode, &OSGNode::nodeChanged, this, &OSGGeoTransformNode::Hidden::onSceneNodeChanged);
        }

        return true;
    }

    void updateSceneNode()
    {
        // qDebug() << "OSGGeoTransformNode::updateSceneNode" << sceneNode;
        if (sceneNode && sceneNode->node()) {
            osgEarth::MapNode *mapNode = osgEarth::MapNode::findMapNode(sceneNode->node());
            if (mapNode) {
                transform->setTerrain(mapNode->getTerrain());
            } else {
                qWarning() << "OSGGeoTransformNode::updateScene - scene data does not contain a map node";
            }
        }
    }

    void updatePosition()
    {
        // qDebug() << "OSGGeoTransformNode::updatePosition" << position;

        osgEarth::MapNode *mapNode = NULL;

        if (sceneNode && sceneNode->node()) {
            mapNode = osgEarth::MapNode::findMapNode(sceneNode->node());
            if (!mapNode) {
                qWarning() << "OSGGeoTransformNode::updatePosition - scene node does not contain a map node";
            }
        } else {
            qWarning() << "OSGGeoTransformNode::updatePosition - scene node is not valid";
        }

        // TODO factorize this logic to utility (same logic is found elsewhere)
        osgEarth::GeoPoint geoPoint;
        if (mapNode) {
            geoPoint = osgQtQuick::toGeoPoint(mapNode->getTerrain()->getSRS(), position);
        } else {
            qWarning() << "OSGGeoTransformNode::onChildNodeChanged - no map node";
            geoPoint = osgQtQuick::toGeoPoint(position);
        }
        if (clampToTerrain && mapNode) {
            // get "size" of model
            // TODO this should be done once only...
            osg::ComputeBoundsVisitor cbv;
            transform->accept(cbv);
            const osg::BoundingBox & bbox = cbv.getBoundingBox();
            offset = bbox.radius();

            // qDebug() << "OSGGeoTransformNode::updateNode - offset" << offset;

            // clamp model to terrain if needed
            intoTerrain = clampGeoPoint(geoPoint, offset, mapNode);
        } else if (clampToTerrain) {
            qWarning() << "OSGGeoTransformNode::onChildNodeChanged - cannot clamp without map node";
        }

        transform->setPosition(geoPoint);
    }

private slots:
    void onSceneNodeChanged(osg::Node *node)
    {
        // qDebug() << "OSGGeoTransformNode::onSceneNodeChanged" << node;
        updateSceneNode();
        updatePosition();
    }
};

/* class OSGGeoTransformNode */

OSGGeoTransformNode::OSGGeoTransformNode(QObject *parent) : Inherited(parent), h(new Hidden(this))
{}

OSGGeoTransformNode::~OSGGeoTransformNode()
{
    delete h;
}

OSGNode *OSGGeoTransformNode::sceneNode() const
{
    return h->sceneNode;
}

void OSGGeoTransformNode::setSceneNode(OSGNode *node)
{
    if (h->acceptSceneNode(node)) {
        setDirty(Scene);
        emit sceneNodeChanged(node);
    }
}

bool OSGGeoTransformNode::clampToTerrain() const
{
    return h->clampToTerrain;
}

void OSGGeoTransformNode::setClampToTerrain(bool arg)
{
    if (h->clampToTerrain != arg) {
        h->clampToTerrain = arg;
        setDirty(Clamp);
        emit clampToTerrainChanged(clampToTerrain());
    }
}

bool OSGGeoTransformNode::intoTerrain() const
{
    return h->intoTerrain;
}

QVector3D OSGGeoTransformNode::position() const
{
    return h->position;
}

void OSGGeoTransformNode::setPosition(QVector3D arg)
{
    if (h->position != arg) {
        h->position = arg;
        setDirty(Position);
        emit positionChanged(position());
    }
}

osg::Node *OSGGeoTransformNode::createNode()
{
    return h->createNode();
}

void OSGGeoTransformNode::updateNode()
{
    Inherited::updateNode();

    if (isDirty(Scene)) {
        h->updateSceneNode();
    }
    if (isDirty(Clamp)) {
        // do nothing...
    }
    if (isDirty(Scene | Clamp | Position)) {
        h->updatePosition();
    }
}
} // namespace osgQtQuick

#include "OSGGeoTransformNode.moc"
