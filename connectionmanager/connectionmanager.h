#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QWidget>
#include <QtCore/QVector>
#include <QtCore/QIODevice>
#include <QtCore/QLinkedList>
#include <QPushButton>
#include <QComboBox>

#include <QTimer>

class ConnectionManager : public QWidget {
  Q_OBJECT

 public:
  ConnectionManager(QWidget *mainWindow);
  virtual ~ConnectionManager();
  
 protected:
  QComboBox *availableDevList;
  QPushButton *connectBtn;
  // currently connected QIODevice
  QIODevice *ioDev;
  
};

#endif // CONNECTIONMANAGER_H
