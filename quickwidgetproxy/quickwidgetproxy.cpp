
#include "quickwidgetproxy.h"

#include <QQmlEngine>
#include <QQmlContext>
#include <QDebug>

/*
 * Note: QQuickWidget is an alternative to using QQuickView and
 * QWidget::createWindowContainer().  The restrictions on stacking
 * order do not apply, making QQuickWidget the more flexible
 * alternative, behaving more like an ordinary widget. This comes at
 * the expense of performance.  Unlike QQuickWindow and QQuickView,
 * QQuickWidget involves rendering into OpenGL framebuffer objects.
 * This will naturally carry a minor performance hit.
 *
 * Note: Using QQuickWidget disables the threaded render loop on all
 * platforms.  This means that some of the benefits of threaded
 * rendering, for example Animator classes and vsync driven
 * animations, will not be available.
 *
 * Note: Avoid calling winId() on a QQuickWidget. This function
 * triggers the creation of a native window, resulting in reduced
 * performance and possibly rendering glitches.  The entire purpose of
 * QQuickWidget is to render Quick scenes without a separate native
 * window, hence making it a native widget should always be avoided.
 */
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

QList<QQmlError> QuickWidgetProxy::errors() const
{
  return quickWidget->errors();
}

void QuickWidgetProxy::setContextProperty(const QString &name, QObject *value)
{
  quickWidget->rootContext()->setContextProperty(name, value); 
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
