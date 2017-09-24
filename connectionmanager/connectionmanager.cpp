#include "connectionmanager.h"
// #include <QtSerialPort/QSerialPort>
// #include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QLabel>
#include <QHBoxLayout>
#include <QComboBox>
// #include <QEventLoop>

QString DevListItem::getConName() const
{
  return "";
}

QString DevListItem::getConDescription() const
{
  return "";
}

ConnectionManager::ConnectionManager(MainWindow *mainWindow) :
  QWidget(mainWindow),
  availableDevList(0),
  connectBtn(0),
  ioDev(NULL),
  polling(true)
{
  // device list
  availableDevList = new QComboBox;
  availableDevList->setMinimumContentsLength(tr("USB: OPLinkMini").length());
  availableDevList->setContextMenuPolicy(Qt::CustomContextMenu);

  // connect button
  connectBtn = new QPushButton(tr("Connect"));
  connectBtn->setEnabled(false);

  // put everything together
  QHBoxLayout *layout = new QHBoxLayout;
  layout->setSpacing(6);
  layout->setContentsMargins(5, 2, 5, 2);
  setLayout(layout);
  
  layout->addWidget(new QLabel(tr("Connections:")), 0, Qt::AlignVCenter);
  layout->addWidget(availableDevList, 0, Qt::AlignVCenter);
  layout->addWidget(connectBtn, 0, Qt::AlignVCenter);
  
  QObject::connect(connectBtn, SIGNAL(clicked()), this, SLOT(onConnectClicked()));
  QObject::connect(availableDevList, SIGNAL(currentIndexChanged(int)), this, SLOT(onDeviceSelectionChanged(int)));

  // setup our reconnect timers
  // TODO these are never started because telemetryConnected is not called anymore
  reconnect = new QTimer(this);
  connect(reconnect, SIGNAL(timeout()), this, SLOT(reconnectSlot()));

  reconnectCheck = new QTimer(this);
  connect(reconnectCheck, SIGNAL(timeout()), this, SLOT(reconnectCheckSlot()));
}

ConnectionManager::~ConnectionManager()
{
  disconnectDevice();
  suspendPolling();
}

// TODO needs documentation?
void ConnectionManager::addConnWidget(QWidget *widget)
{
    QHBoxLayout *l = (QHBoxLayout *)layout();

    l->insertWidget(0, widget, 0, Qt::AlignVCenter);
}

/**
 *   Method called when the user clicks the "Connect" button
 */
bool ConnectionManager::connectDevice(DevListItem device)
{
    Q_UNUSED(device);
   return false;
}

/**
 *   Method called by plugins who want to force a disconnection.
 *   Used by Uploader gadget for instance.
 */
bool ConnectionManager::disconnectDevice()
{
    if (!ioDev) {
        // apparently we are already disconnected: this can
        // happen if a plugin tries to force a disconnect whereas
        // we are not connected. Just return.
        return false;
    }

    // We are connected - disconnect from the device

    // stop our timers
    if (reconnect->isActive()) {
        reconnect->stop();
    }
    if (reconnectCheck->isActive()) {
        reconnectCheck->stop();
    }

    // signal interested plugins that user is disconnecting his device
    emit deviceAboutToDisconnect();


    ioDev = NULL;

    // signal interested plugins that we disconnected from the device
    emit deviceDisconnected();

    connectBtn->setText(tr("Connect"));
    availableDevList->setEnabled(true);

    return true;
}


void ConnectionManager::onConnectionDestroyed(QObject *obj)
{
    Q_UNUSED(obj)
    disconnectDevice();
}

/**
 *   Slot called when the user selects a device from the combo box
 */
void ConnectionManager::onDeviceSelectionChanged(int index)
{
    if (index >= 0) {
        QString deviceName = availableDevList->itemData(index, Qt::ToolTipRole).toString();
        availableDevList->setToolTip(deviceName);
    }
}

/**
 *   Slot called when the user clicks the connect/disconnect button
 */
void ConnectionManager::onConnectClicked()
{
    // Check if we have a ioDev already created:
    if (!ioDev) {
        // connecting to currently selected device
        DevListItem device = findDevice(availableDevList->currentIndex());
        Q_UNUSED(device);
    } else {
        // disconnecting
        disconnectDevice();
    }
}

/**
 *   Slot called when the telemetry is connected
 */
void ConnectionManager::telemetryConnected()
{
    qDebug() << "ConnectionManager::telemetryConnected";

    if (reconnectCheck->isActive()) {
        reconnectCheck->stop();
    }
}

/**
 *   Slot called when the telemetry is disconnected
 */
void ConnectionManager::telemetryDisconnected()
{
    qDebug() << "ConnectionManager::telemetryDisconnected";

    if (ioDev) {
    }
}

void ConnectionManager::reconnectSlot()
{
    qDebug() << "ConnectionManager::reconnectSlot";

    if (ioDev->isOpen()) {
        ioDev->close();
    }

    if (ioDev->open(QIODevice::ReadWrite)) {
        qDebug() << "ConnectionManager::reconnectSlot - reconnect successful";
        reconnect->stop();
        reconnectCheck->start(20000);
    } else {
        qDebug() << "ConnectionManager::reconnectSlot - reconnect NOT successful";
    }
}

void ConnectionManager::reconnectCheckSlot()
{
    reconnectCheck->stop();
    reconnect->start(1000);
}

/**
 *   Find a device by its displayed (visible on screen) name
 */
DevListItem ConnectionManager::findDevice(int devNumber)
{
    foreach(DevListItem d, devList) {
        if (d.displayNumber == devNumber) {
            return d;
        }
    }

    qWarning() << "ConnectionManager::findDevice - cannot find " << devNumber << " in device list";

    DevListItem d;
    return d;
}

/**
 *   Tells every connection plugin to stop polling for devices if they
 *   are doing that.
 *
 */
void ConnectionManager::suspendPolling()
{
    connectBtn->setEnabled(false);
    availableDevList->setEnabled(false);
    polling = false;
}

/**
 *   Tells every connection plugin to resume polling for devices if they
 *   are doing that.
 */
void ConnectionManager::resumePolling()
{
    connectBtn->setEnabled(true);
    availableDevList->setEnabled(true);
    polling = true;
}



void ConnectionManager::updateConnectionDropdown()
{
  return;
}

