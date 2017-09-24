#ifndef _H_OSGQTQUICK_FILENODE_H_
#define _H_OSGQTQUICK_FILENODE_H_

#include "Export.hpp"
#include "OSGNode.hpp"

#include <QUrl>
QT_BEGIN_NAMESPACE
class QUrl;
QT_END_NAMESPACE

namespace osgQtQuick {
class OSGQTQUICK_EXPORT OptimizeMode : public QObject {
    Q_OBJECT

public:
    enum Enum { None, Optimize, OptimizeAndCheck };
    Q_ENUMS(Enum) // TODO switch to Q_ENUM once on Qt 5.5
};

class OSGQTQUICK_EXPORT OSGFileNode : public OSGNode {
    Q_OBJECT Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(bool async READ async WRITE setAsync NOTIFY asyncChanged)
    Q_PROPERTY(osgQtQuick::OptimizeMode::Enum optimizeMode READ optimizeMode WRITE setOptimizeMode NOTIFY optimizeModeChanged)

    typedef OSGNode Inherited;

public:
    OSGFileNode(QObject *parent = 0);
    virtual ~OSGFileNode();

    const QUrl source() const;
    void setSource(const QUrl &url);

    bool async() const;
    void setAsync(const bool async);

    OptimizeMode::Enum optimizeMode() const;
    void setOptimizeMode(OptimizeMode::Enum);

signals:
    void sourceChanged(const QUrl &url);
    void asyncChanged(const bool async);
    void optimizeModeChanged(OptimizeMode::Enum);

protected:
    virtual osg::Node *createNode();
    virtual void updateNode();

private:
    struct Hidden;
    Hidden *const h;
};
} // namespace osgQtQuick

#endif // _H_OSGQTQUICK_FILENODE_H_
