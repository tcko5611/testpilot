#include <QApplication>
#include <QSettings>
#include <QMap>
#include <QString>
#include <QDebug>
#include <QDir>

#include "utils/pathutils.h"
#include "utils/xmlconfig.h"

typedef QMap<QString, QString> AppOptionValues;

void loadFactoryDefaults(QSettings &settings, AppOptionValues &appOptionValues)
{
  QDir directory(Utils::GetDataPath() + QString("configurations"));
  
  qDebug() << "Looking for factory defaults configuration files in:" << directory.absolutePath();
  
  QString fileName;
  
  if (QFile::exists(directory.absolutePath() + QDir::separator() + DEFAULT_CONFIG_FILENAME)) {
    fileName = directory.absolutePath() + QDir::separator() + DEFAULT_CONFIG_FILENAME;
    qDebug() << "Default configuration file" << fileName << "will be loaded.";
  } else {
    qWarning() << "No default configuration file found in" << directory.absolutePath();
  }
  
  if (fileName.isEmpty()) {
    // TODO should we exit violently?
    qCritical() << "No default configuration file found!";
    return;
  }
  
  // create settings from file
  QSettings qs(fileName, XmlConfig::XmlSettingsFormat);
  
  // transfer loaded settings to application settings
  QStringList keys = qs.allKeys();
  foreach(QString key, keys) {
    settings.setValue(key, qs.value(key));
  }
  qDebug() << "Configuration file" << fileName << "was loaded.";
}


int main(int argc, char * *argv)
{
  QApplication app(argc, argv);
  
  QCoreApplication::setApplicationName(APP_NAME);
  QCoreApplication::setOrganizationName(ORG_NAME);
  QCoreApplication::setOrganizationDomain(ORG_DOMAIN);
  QSettings::setDefaultFormat(XmlConfig::XmlSettingsFormat);
  
  QString settingsPath = Utils::GetDataPath();
  qDebug() << "Loading system settings from" << settingsPath;
  QSettings::setPath(XmlConfig::XmlSettingsFormat, QSettings::SystemScope, settingsPath);
  QSettings settings;
  AppOptionValues appOptionValues;
  qDebug() << "Loading user settings from" << settings.fileName();
  if (!settings.allKeys().count()) {
    // no user settings, load the factory defaults
    qDebug() << "No user settings found, loading factory defaults...";
    loadFactoryDefaults(settings, appOptionValues);
  }
  settings.beginGroup(QLatin1String("IPconnection"));

  settings.beginReadArray("Current");
  settings.setArrayIndex(0);
  qDebug() << (settings.value(QLatin1String("HostName"),QObject::tr("")).toString());
  qDebug() << (settings.value(QLatin1String("Port"), QObject::tr("")).toInt());
  qDebug() << (settings.value(QLatin1String("UseTCP"), QObject::tr("")).toInt());
  settings.endArray();
  settings.endGroup();
  
  return 0;
}
