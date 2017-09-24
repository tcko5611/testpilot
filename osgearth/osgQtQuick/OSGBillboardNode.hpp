#ifndef _H_OSGQTQUICK_BILLBOARDNODE_H_
#define _H_OSGQTQUICK_BILLBOARDNODE_H_

#include "Export.hpp"
#include "OSGGroup.hpp"

namespace osgQtQuick {
class OSGQTQUICK_EXPORT OSGBillboardNode : public OSGGroup {
    Q_OBJECT

    typedef OSGGroup Inherited;

public:
    OSGBillboardNode(QObject *parent = 0);
    virtual ~OSGBillboardNode();

protected:
    virtual osg::Node *createNode();
    virtual void updateNode();

private:
    struct Hidden;
    Hidden *const h;
};
} // namespace osgQtQuick

#endif // _H_OSGQTQUICK_BILLBOARDNODE_H_
