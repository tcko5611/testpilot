#ifndef _H_OSGQTQUICK_DIRTYSUPPORT_H_
#define _H_OSGQTQUICK_DIRTYSUPPORT_H_

namespace osg {
class Node;
} // namespace osg

namespace osgQtQuick {
/**
 * Provides support to:
 * - manage dirty state flags
 * - add/remove node callback to trigger refresh (compatible with viewer on demand mode)
 */
class DirtySupport {
public:
    explicit DirtySupport();
    virtual ~DirtySupport();

protected:
    int dirty() const;
    bool isDirty(int mask = 0xFFFF) const;
    void setDirty(int mask = 0xFFFF);
    void clearDirty();

private:
    struct Hidden;
    struct NodeUpdateCallback;
    Hidden *const h;

    virtual osg::Node *nodeToUpdate() const = 0;

    virtual void update() = 0;
};
} // namespace osgQtQuick

#endif // _H_OSGQTQUICK_DIRTYSUPPORT_H_
