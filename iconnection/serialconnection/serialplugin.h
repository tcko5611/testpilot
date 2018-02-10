/**
 ******************************************************************************
 *
 * @file       serialplugin.h
 * @author     The LibrePilot Project, http://www.librepilot.org Copyright (C) 2017.
 *             The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup SerialPlugin Serial Connection Plugin
 * @{
 * @brief Impliments serial connection to the flight hardware for Telemetry
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef SERIALPLUGIN_H
#define SERIALPLUGIN_H

#include "serial_global.h"

#include "serialconfig.h"
#include "serialoptionspage.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <QThread>

class IConnection;
class QSerialPortInfo;
class SerialConnection;

/**
 *   Helper thread to check on new serial port connection/disconnection
 *   Some operating systems do not send device insertion events so
 *   for those we have to poll
 */
// class SERIAL_EXPORT SerialEnumerationThread : public QThread
class SerialRunnable : public QThread {
  Q_OBJECT
public:
  SerialRunnable(SerialConnection *serial);
  
  virtual void run();

  void stop();
  
signals:
  void enumerationChanged();
  
protected:
  SerialConnection *m_connection;
  bool m_running;
};


/**
 *   Define a connection via the IConnection interface
 *   Plugin will add a instance of this class to the pool,
 *   so the connection manager can use it.
 */
class SerialConnection : public QObject {
  Q_OBJECT
public:
  SerialConnection(SerialConfig *config, QObject *parent = 0);
  ~SerialConnection();
  
  QList<QSerialPortInfo> availablePorts();
  QIODevice *openDevice(const QString &deviceName);
  void closeDevice(const QString &deviceName);

  QString connectionName();
  QString shortName();
  void suspendPolling();
  void resumePolling();
  
  bool deviceOpened()
  {
    return m_deviceOpened;
  }
  
  SerialOptionsPage *optionsPage() const
  {
    return m_optionsPage;
  }
  QStringList getComNames();
			      
protected slots:
  void onEnumerationChanged();
  
  
private:
  QSerialPort *m_serialHandle;
  bool m_enablePolling;
  
  SerialRunnable m_runnable;
  bool m_deviceOpened;
  
  // FIXME m_config and m_optionsPage belong in IPConnectionPlugin
  SerialConfig *m_config;
  SerialOptionsPage *m_optionsPage;
signals:
  void availableDevChanged(SerialConnection *);
};


class SERIAL_EXPORT SerialPlugin : public QObject {
  Q_OBJECT
  // Q_PLUGIN_METADATA(IID "OpenPilot.Serial")
  
public:
  SerialPlugin();
  ~SerialPlugin();
  QWidget *optionsWidget();  
private:
  SerialConfig *m_config;
  SerialConnection *m_connection;
  SerialOptionsPage *m_optionsPage;
};

#endif // SERIALPLUGIN_H
// Local Variables:
// Mode: c++
// End:
