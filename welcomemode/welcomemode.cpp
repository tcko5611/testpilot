
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

WelcomeMode::WelcomeMode() :
    quickWidgetProxy(NULL),
    _newVersionText("")
{
  QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager;
  
  // Only attempt to request our version info if the network is accessible
  if (networkAccessManager->networkAccessible() == QNetworkAccessManager::Accessible) {
    connect(networkAccessManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(networkResponseReady(QNetworkReply *)));
    
    // This will delete the network access manager instance when we're done
    connect(networkAccessManager, SIGNAL(finished(QNetworkReply *)), networkAccessManager, SLOT(deleteLater()));
    
    networkAccessManager->get(QNetworkRequest(QUrl("http://www.librepilot.org/stable-version")));
  } else {
    // No network, can delete this now as we don't need it.
    delete networkAccessManager;
  }
}

WelcomeMode::~WelcomeMode()
{}

QString WelcomeMode::name() const
{
  return tr("Welcome");
}

QIcon WelcomeMode::icon() const
{
  return QIcon(QLatin1String(":/images/librepiloticon.png"));
}


QWidget *WelcomeMode::widget()
{
  if (!quickWidgetProxy) {
    quickWidgetProxy = new QuickWidgetProxy();
    // qWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickWidgetProxy->engine()->rootContext()->setContextProperty("welcomePlugin", this);
    quickWidgetProxy->setSource(QUrl("qrc:/qml/main.qml"));
  }
  return quickWidgetProxy->widget();
}

const char *WelcomeMode::uniqueModeName() const
{
  return "Welcome";
}
/*
QList<int> WelcomeMode::context() const
{
  static QList<int> contexts = QList<int>()
    << Core::UniqueIDManager::instance()->uniqueIdentifier(Core::Constants::C_WELCOME_MODE);
  
  return contexts;
}
*/

void WelcomeMode::openUrl(const QString &url)
{
    QDesktopServices::openUrl(QUrl(url));
}

void WelcomeMode::openPage(const QString &page)
{
    Q_UNUSED(page);
    // Core::ModeManager::instance()->activateModeByWorkspaceName(page);
}
void WelcomeMode::triggerAction(const QString &actionId)
{
    Q_UNUSED(actionId);
    // Core::ModeManager::instance()->triggerAction(actionId);
}

void WelcomeMode::networkResponseReady(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    /*
  if (reply != NULL) {
    QString version(reply->readAll());
    version = version.trimmed();
    
    reply->deleteLater();
    
    if (version != VersionInfo::tagOrHash8()) {
      m_newVersionText = tr("Update Available: %1").arg(version);
      emit newVersionTextChanged();
    }
  }
  */
}
