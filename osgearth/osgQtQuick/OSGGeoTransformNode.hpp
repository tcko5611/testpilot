#ifndef _H_OSGQTQUICK_GEOTRANSFORMNODE_H_
#define _H_OSGQTQUICK_GEOTRANSFORMNODE_H_

#include "Export.hpp"
#include "OSGGroup.hpp"

#include <QVector3D>

namespace osgQtQuick {
class OSGQTQUICK_EXPORT OSGGeoTransformNode : public OSGGroup {
    Q_OBJECT Q_PROPERTY(osgQtQuick::OSGNode *sceneNode READ sceneNode WRITE setSceneNode NOTIFY sceneNodeChanged)
    Q_PROPERTY(bool clampToTerrain READ clampToTerrain WRITE setClampToTerrain NOTIFY clampToTerrainChanged)
    Q_PROPERTY(bool intoTerrain READ intoTerrain NOTIFY intoTerrainChanged)
    Q_PROPERTY(QVector3D position READ position WRITE setPosition NOTIFY positionChanged)

    typedef OSGGroup Inherited;

public:
    OSGGeoTransformNode(QObject *parent = 0);
    virtual ~OSGGeoTransformNode();

    OSGNode *sceneNode() const;
    void setSceneNode(OSGNode *node);

    bool clampToTerrain() const;
    void setClampToTerrain(bool arg);

    bool intoTerrain() const;

    QVector3D position() const;
    void setPosition(QVector3D arg);

signals:
    void sceneNodeChanged(OSGNode *node);
    void clampToTerrainChanged(bool arg);
    void intoTerrainChanged(bool arg);
    void positionChanged(QVector3D arg);

protected:
    virtual osg::Node *createNode();
    virtual void updateNode();

private:
    struct Hidden;
    Hidden *const h;
};
} // namespace osgQtQuick

#endif // _H_OSGQTQUICK_GEOTRANSFORMNODE_H_
