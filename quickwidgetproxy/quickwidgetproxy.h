#ifndef QUICKWIDGETPROXY_H_
#define QUICKWIDGETPROXY_H_

#include <QWidget>
#include <QQuickWidget>

class QQmlEngine;
class QQmlImageProviderBase;

class QuickWidgetProxy : public QObject {
  Q_OBJECT

 public:
  QuickWidgetProxy(QWidget *parent = 0);
  virtual ~QuickWidgetProxy();

  QString name() const;
  void setName(const QString &);
  QIcon icon() const;
  void setIcon(const QString &);
  QWidget *widget();
  
  void setSource(const QUrl &url);
  void setBaseUrl(const QUrl &url);
  QQmlEngine *engine() const;
  void setContextProperty(const QString &name, QObject *value);
  void setEngineContextProperty(const QString &name, QObject *value);
  void addImageProvider(const QString &providerId, QQmlImageProviderBase *provider);
  void removeImageProvider(const QString &providerId);
  QList<QQmlError> errors() const;
  
 public slots:
    void onStatusChanged(QQuickWidget::Status status);
    void onSceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

 private:
    QString _name;
    QIcon _icon;
    QQuickWidget *quickWidget;
};

#endif /* QUICKWIDGETPROXY_H_ */
