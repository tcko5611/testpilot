#ifndef _H_OSGQTQUICK_IMAGENODE_H_
#define _H_OSGQTQUICK_IMAGENODE_H_

#include "Export.hpp"
#include "OSGNode.hpp"

#include <QUrl>

namespace osgQtQuick {
class OSGQTQUICK_EXPORT OSGImageNode : public OSGNode {
    Q_OBJECT Q_PROPERTY(QUrl imageFile READ imageFile WRITE setImageFile NOTIFY imageFileChanged)

    typedef OSGNode Inherited;

public:
    OSGImageNode(QObject *parent = 0);
    virtual ~OSGImageNode();

    const QUrl imageFile() const;
    void setImageFile(const QUrl &url);

signals:
    void imageFileChanged(const QUrl &url);

protected:
    virtual osg::Node *createNode();
    virtual void updateNode();

private:
    struct Hidden;
    Hidden *const h;
};
} // namespace osgQtQuick

#endif // _H_OSGQTQUICK_IMAGENODE_H_
