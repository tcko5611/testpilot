#ifndef PFDQMLMODE_H
#define PFDQMLMODE_H

class QuickWidgetProxy;
class QWidget;
class QUrl;
class QNetworkReply;
#include <QtCore/QObject>
class SvgImageProvider;

class  PfdQmlMode : public QObject {
 public:
  PfdQmlMode(QString qmlName);
  ~PfdQmlMode();
  
  // IMode
  QString name() const;
  QIcon icon() const;
  QWidget *widget();
  void activated();
  void setSource();
  void setContextProperty(const QString &name, QObject *value);
 private:
  QString _qmlName;
  QuickWidgetProxy *_quickWidgetProxy;
  SvgImageProvider *_svgProvider;
};

#endif // PFDQMLMODE_H
