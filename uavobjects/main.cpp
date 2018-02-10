#include "uavobjectmanager.h"
#include "uavobjectsinit.h"
#include <iostream>
#include <string>
int main(int argc, char *argv[])
{
  UAVObjectsInitialize();
  UAVObjectManager& s = UAVObjectManager::getInstance();
  QList< QList<UAVDataObject *> > l = s.getDataObjects();
	QList<UAVDataObject *> objs1;
  for (int i = 0; i< l.length(); ++i) {
		QString str = l[i][0]->getName();
		str = str.replace(0,1,str[0].toLower());
    std::cout << str.toStdString() << std::endl;
  }
  return 0;
}
