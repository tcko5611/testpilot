#include "pfdqmlmode.h"
#include "quickwidgetproxy.h"
#include "svgimageprovider.h"

#include <QDesktopServices>

#include <QtCore/QSettings>
#include <QtCore/QUrl>
#include <QtCore/QDebug>

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QtQuick>
#include <QQuickWidget>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFileInfo>
#include <iostream>
#include <cstdlib>

PfdQmlMode::PfdQmlMode(QString name) :
  _qmlName(name)
{
  _quickWidgetProxy = new QuickWidgetProxy();
  QFileInfo check_file(_qmlName);
  if (check_file.exists() && check_file.isFile()) {
    std::cout << "2. file exist" << std::endl;
  } else {
    std::cout << "2. file not exist" << std::endl;
  }

  _svgProvider = new SvgImageProvider(_qmlName);
  _quickWidgetProxy->engine()->addImageProvider("svg", _svgProvider);
  _quickWidgetProxy->engine()->rootContext()->setContextProperty("svgRenderer", _svgProvider);

}

PfdQmlMode::~PfdQmlMode()
{
  delete _svgProvider;
  delete _quickWidgetProxy;
}

void PfdQmlMode::setContextProperty(const QString &name, QObject *value) {
   _quickWidgetProxy->setContextProperty(name, value);
}

void PfdQmlMode::setSource() {
  QUrl url = QUrl::fromLocalFile(_qmlName);
  _quickWidgetProxy->setSource(url);
}

QString PfdQmlMode::name() const
{
  return tr("PfdQml");
}

QIcon PfdQmlMode::icon() const
{
  return QIcon(QLatin1String(":/images/librepiloticon.png"));
}


QWidget *PfdQmlMode::widget()
{
  return _quickWidgetProxy->widget();
}

