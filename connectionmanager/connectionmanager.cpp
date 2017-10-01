#include "connectionmanager.h"
#include <QDebug>
#include <QLabel>
#include <QHBoxLayout>
#include <QComboBox>

ConnectionManager::ConnectionManager(QWidget *mainWindow) :
  QWidget(mainWindow),
  availableDevList(0),
  connectBtn(0),
  ioDev(NULL)
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
  
}

ConnectionManager::~ConnectionManager()
{
}





