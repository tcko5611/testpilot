#ifndef WELCOMEMODE_H
#define WELCOMEMODE_H

class QuickWidgetProxy;
class QWidget;
class QUrl;
class QNetworkReply;
#include <QtCore/QObject>

class  WelcomeMode : public QObject {
  Q_OBJECT Q_PROPERTY(QString versionString READ versionString CONSTANT)
  Q_PROPERTY(QString newVersionText READ newVersionText NOTIFY newVersionTextChanged)

public:
  WelcomeMode();
  ~WelcomeMode();
  
  // IMode
  QString name() const;
  QIcon icon() const;
  QWidget *widget();
  const char *uniqueModeName() const;
  //  QList<int> context() const;
  void activated();
  QString contextHelpId() const
  {
    return QLatin1String("TestPilot");
  }
  QString versionString() const
  {
    return tr("%1 Version: %2 ").arg("TestPilot").arg("1.0");
  }
  QString newVersionText() const
  {
    return _newVersionText;
  }
  
 signals:
  void newVersionTextChanged();
  
 public slots:
    void openUrl(const QString &url);
    void openPage(const QString &page);
    void triggerAction(const QString &actionId);
    
 private:
    QuickWidgetProxy *quickWidgetProxy;
    QString _newVersionText;
    
 private slots:
   void networkResponseReady(QNetworkReply *reply);
};

#endif // WELCOMEMODE_H
