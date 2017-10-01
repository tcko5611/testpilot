
#include "welcomemode.h"
#include "quickwidgetproxy.h"

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

#include <cstdlib>

WelcomeMode::WelcomeMode()
{
  quickWidgetProxy = new QuickWidgetProxy();
  quickWidgetProxy->setEngineContextProperty("welcomePlugin", this);
  quickWidgetProxy->setSource(QUrl("qrc:/qml/main.qml"));
  quickWidgetProxy->setIcon(":/images/librepiloticon.png");
  quickWidgetProxy->setName("Welcome");
}

WelcomeMode::~WelcomeMode()
{}

QString WelcomeMode::name() const
{
  return quickWidgetProxy->name();
}

QIcon WelcomeMode::icon() const
{
  return quickWidgetProxy->icon();
}


QWidget *WelcomeMode::widget()
{
  return quickWidgetProxy->widget();
}

const char *WelcomeMode::uniqueModeName() const
{
  return "Welcome";
}

void WelcomeMode::openUrl(const QString &url)
{
  QDesktopServices::openUrl(QUrl(url));
}

void WelcomeMode::openPage(const QString &page)
{
  Q_UNUSED(page);
}

void WelcomeMode::triggerAction(const QString &actionId)
{
  Q_UNUSED(actionId);
}

void WelcomeMode::networkResponseReady(QNetworkReply *reply)
{
  Q_UNUSED(reply);
}
