#ifndef _H_OSGQTQUICK_OSGGROUP_H_
#define _H_OSGQTQUICK_OSGGROUP_H_

#include "Export.hpp"
#include "OSGNode.hpp"

#include <QQmlListProperty>

namespace osgQtQuick {
class OSGQTQUICK_EXPORT OSGGroup : public OSGNode {
    Q_OBJECT Q_PROPERTY(QQmlListProperty<osgQtQuick::OSGNode> children READ children)

    Q_CLASSINFO("DefaultProperty", "children")

    typedef OSGNode Inherited;

public:
    explicit OSGGroup(QObject *parent = 0);
    virtual ~OSGGroup();

    QQmlListProperty<OSGNode> children() const;

protected:
    virtual osg::Node *createNode();
    virtual void updateNode();

private:
    struct Hidden;
    Hidden *const h;
};
} // namespace osgQtQuick

#endif // _H_OSGQTQUICK_OSGGROUP_H_
