
#include "quickwidgetproxy.h"

#include <QQmlEngine>
#include <QQmlContext>
#include <QDebug>

QuickWidgetProxy::QuickWidgetProxy(QWidget *parent) : QObject(parent)
{
  quickWidget = new QQuickWidget(parent);
  quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
  
  connect(quickWidget, &QQuickWidget::statusChanged,
	  this, &QuickWidgetProxy::onStatusChanged);
  connect(quickWidget, &QQuickWidget::sceneGraphError,
	  this, &QuickWidgetProxy::onSceneGraphError);
}

QuickWidgetProxy::~QuickWidgetProxy()
{
  delete quickWidget;
}

QString QuickWidgetProxy::name() const
{
  return _name;
}

QIcon QuickWidgetProxy::icon() const
{
  return _icon;
}

void QuickWidgetProxy::setIcon(const QString &fn)
{
  _icon = QIcon(fn);
}
void QuickWidgetProxy::setName(const QString &name)
{
  _name = name;
}

QWidget *QuickWidgetProxy::widget()
{
  return quickWidget;
}

QQmlEngine *QuickWidgetProxy::engine() const
{
  return quickWidget->engine();
}

void QuickWidgetProxy::setSource(const QUrl &url)
{
  quickWidget->setSource(url);
}

void QuickWidgetProxy::setBaseUrl(const QUrl &url)
{
  engine()->setBaseUrl(url);
}

QList<QQmlError> QuickWidgetProxy::errors() const
{
  return quickWidget->errors();
}

void QuickWidgetProxy::setContextProperty(const QString &name, QObject *value)
{
  quickWidget->rootContext()->setContextProperty(name, value); 
}

void QuickWidgetProxy::setEngineContextProperty(const QString &name, QObject *value)
{
  engine()->rootContext()->setContextProperty(name, value); 
}

void QuickWidgetProxy::addImageProvider(const QString &providerId, QQmlImageProviderBase *provider)
{
  engine()->addImageProvider(providerId, provider);
}

void QuickWidgetProxy::removeImageProvider(const QString &providerId)
{
  engine()->removeImageProvider(providerId);
}

void QuickWidgetProxy::onStatusChanged(QQuickWidget::Status status)
{
  switch (status) {
  case QQuickWidget::Null:
    qWarning() << "QuickWidgetProxy - status Null";
    break;
  case QQuickWidget::Ready:
    // qDebug() << "QuickWidgetProxy - status Ready";
    break;
  case QQuickWidget::Loading:
    // qDebug() << "QuickWidgetProxy - status Loading";
    break;
  case QQuickWidget::Error:
    qWarning() << "QuickWidgetProxy - status Error";
    foreach(const QQmlError &error, errors()) {
      qWarning() << error.description();
    }
    break;
  }
}

void QuickWidgetProxy::onSceneGraphError(QQuickWindow::SceneGraphError error, const QString &message)
{
  qWarning() << QString("Scenegraph error %1: %2").arg(error).arg(message);
}
