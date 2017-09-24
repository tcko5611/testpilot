#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include "mainwindow.h"
#include <QWidget>
#include <QtCore/QVector>
#include <QtCore/QIODevice>
#include <QtCore/QLinkedList>
#include <QPushButton>
#include <QComboBox>

#include <QTimer>

class MainWindow;

class DevListItem {
 public:
  
  DevListItem() {}
  
  QString getConName() const;
  
  QString getConDescription() const;
  
  bool operator==(const DevListItem &rhs)
  {
      Q_UNUSED(rhs);
    return true;
  }
  
  int displayNumber = -1;
};


class ConnectionManager : public QWidget {
  Q_OBJECT

public:
  ConnectionManager(MainWindow *mainWindow);
  virtual ~ConnectionManager();
  
  DevListItem getCurrentDevice()
  {
    return connectionDevice;
  }
  DevListItem findDevice(int devNumber);
    
  QLinkedList<DevListItem> getAvailableDevices()
  {
    return devList;
  }
  
  bool isConnected()
  {
    return ioDev != 0;
  }

  void addConnWidget(QWidget *widget);
  
  bool connectDevice(DevListItem device);
  bool disconnectDevice();
  void suspendPolling();
  void resumePolling();
  
 protected:
  void updateConnectionDropdown();
  
 signals:
  void deviceAboutToDisconnect();
  void deviceDisconnected();
  void availableDevicesChanged(const QLinkedList<DevListItem> devices);
  
 public slots:
  void telemetryConnected();
  void telemetryDisconnected();
   
 private slots:
  
  void onConnectClicked();
  void onDeviceSelectionChanged(int index);
  
  void onConnectionDestroyed(QObject *obj);

  void reconnectSlot();
  void reconnectCheckSlot();
  
 protected:
  QComboBox *availableDevList;
  QPushButton *connectBtn;
  QLinkedList<DevListItem> devList;
  
  // currently connected connection plugin
  DevListItem connectionDevice;
  
  // currently connected QIODevice
  QIODevice *ioDev;
  
 private:
  bool connectDevice();
  bool polling;
  QTimer *reconnect;
  QTimer *reconnectCheck;
};

#endif // CONNECTIONMANAGER_H
