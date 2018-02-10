/**
 ******************************************************************************
 *
 * @file       serialplugin.cpp
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

#include "serialplugin.h"

#include <QDebug>
#include <QThread>

SerialRunnable::SerialRunnable(SerialConnection *connection)
  : m_connection(connection), m_running(false)
{}

void SerialRunnable::run()
{
  m_running = true;
  QList <QSerialPortInfo> devices = m_connection->availablePorts();
  while (m_running) {
    if (!m_connection->deviceOpened()) {
      QList <QSerialPortInfo> newDev = m_connection->availablePorts();
      if (devices.size() != newDev.size()) {
	devices = newDev;
	emit enumerationChanged();
      }
    }
    // update available devices every two seconds (doesn't need more)
    msleep(2000);
  }
}

void SerialRunnable::stop()
{
  if (!m_running) {
    return;
  }
  m_running = false;
  // wait for the thread to terminate
  if (wait(2100) == false) {
    qDebug() << "Cannot terminate SerialRunnable";
  }
}

SerialConnection::SerialConnection(SerialConfig *config, QObject *parent) :
  QObject(parent),
  m_serialHandle(NULL),
  m_enablePolling(true),
  m_runnable(this),
  m_deviceOpened(false),
  m_config(config)
{
  m_optionsPage = new SerialOptionsPage(m_config, this);
  
  
  // Experimental: enable polling on all OS'es since there
  // were reports that autodetect does not work on XP amongst
  // others.
  
  // #ifdef Q_OS_WIN
  ////I'm cheating a little bit here:
  ////Knowing if the device enumeration really changed is a bit complicated
  ////so I just signal it whenever we have a device gevent...
  // QMainWindow *mw = Core::ICore::instance()->mainWindow();
  // QObject::connect(mw, SIGNAL(deviceChange()),
  // this, SLOT(onEnumerationChanged()));
  // #else
  // Other OSes do not send such signals:
  QObject::connect(&m_runnable, SIGNAL(enumerationChanged()), this, SLOT(onEnumerationChanged()));
  QObject::connect(m_optionsPage, SIGNAL(availableDevChanged()), this, SLOT(onEnumerationChanged()));
  m_runnable.start();
  // #endif
}

SerialConnection::~SerialConnection()
{
  m_runnable.stop();
}

void SerialConnection::onEnumerationChanged()
{
  if (m_enablePolling) {
    emit availableDevChanged(this);
  }
}

QList<QSerialPortInfo> SerialConnection::availablePorts()
{
  QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
#if QT_VERSION == 0x050301 && defined(Q_OS_WIN)
  // workaround to QTBUG-39748 (https://bugreports.qt-project.org/browse/QTBUG-39748)
  // Qt 5.3.1 reports spurious ports with an empty description...
  QMutableListIterator<QSerialPortInfo> i(ports);
  while (i.hasNext()) {
    if (i.next().description().isEmpty()) {
      i.remove();
    }
  }
#endif
  return ports;
}

QStringList SerialConnection::getComNames()
{
  QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
  QStringList names;
  QMutableListIterator<QSerialPortInfo> i(ports);
  while (i.hasNext()) {
    QString s = i.next().portName();
    if (!s.isEmpty()) {
      names << s;
    }
  }
  return names;
}


QIODevice *SerialConnection::openDevice(const QString &deviceName)
{
  if (m_serialHandle) {
    closeDevice(deviceName);
  }
  QList<QSerialPortInfo> ports = availablePorts();
  foreach(QSerialPortInfo port, ports) {
    if (port.portName() == deviceName) {
      // don't specify a parent when constructing the QSerialPort as this object will be moved
      // to a different thread later on (see telemetrymanager.cpp)
      m_serialHandle = new QSerialPort(port);
      connect(m_serialHandle, static_cast<void(QSerialPort::*) (QSerialPort::SerialPortError)>(&QSerialPort::error),
	      [ = ](QSerialPort::SerialPortError error) { qWarning() << "serial port error:" << error; }
      );
      // we need to handle port settings here...
      if (m_serialHandle->open(QIODevice::ReadWrite)) {
	if (m_serialHandle->setBaudRate(m_config->speed().toInt())
	    && m_serialHandle->setDataBits(QSerialPort::Data8)
	    && m_serialHandle->setParity(QSerialPort::NoParity)
	    && m_serialHandle->setStopBits(QSerialPort::OneStop)
	    && m_serialHandle->setFlowControl(QSerialPort::NoFlowControl)) {
	  qDebug() << "Serial telemetry running at " << m_config->speed();
	  m_deviceOpened = true;
	}
	// see https://librepilot.atlassian.net/browse/LP-341
	m_serialHandle->setDataTerminalReady(true);
      }
      return m_serialHandle;
    }
  }
  return NULL;
}

void SerialConnection::closeDevice(const QString &deviceName)
{
  Q_UNUSED(deviceName);
  // we have to delete the serial connection we created
  if (m_serialHandle) {
    m_serialHandle->deleteLater();
    m_serialHandle = NULL;
  }
  m_deviceOpened = false;
}

QString SerialConnection::connectionName()
{
  return QString("Serial port");
}

QString SerialConnection::shortName()
{
  return QString("Serial");
}

/**
   Tells the Serial plugin to stop polling for serial devices
*/
void SerialConnection::suspendPolling()
{
  m_enablePolling = false;
}

/**
   Tells the Serial plugin to resume polling for serial devices
*/
void SerialConnection::resumePolling()
{
  m_enablePolling = true;
}

SerialPlugin::SerialPlugin() : m_connection(0)
{
  m_config = new SerialConfig(this);
  m_connection = new SerialConnection(m_config, this);
  m_optionsPage = new SerialOptionsPage(m_config, this);
}

SerialPlugin::~SerialPlugin()
{
  // removeObject(m_connection->optionsPage());
}

QWidget *SerialPlugin::optionsWidget()
{
  QWidget *w = m_optionsPage->createPage();
  m_optionsPage->setComList(m_connection->getComNames()); 
  return w;
}
