#ifndef UAVOBJECTMANAGER_H
#define UAVOBJECTMANAGER_H

#include "uavobjects_global.h"
#include "uavobject.h"
#include "uavdataobject.h"
#include "uavmetaobject.h"
#include <QList>
#include <QMutex>
#include <QMutexLocker>
#include <QJsonObject>

class UAVOBJECTS_EXPORT UAVObjectManager : public QObject {
  Q_OBJECT
 public:
  // sigleton pattern
  static UAVObjectManager& getInstance() {
    static UAVObjectManager instance;
    return instance;
  }
 private:
  UAVObjectManager();
  ~UAVObjectManager();
  UAVObjectManager(UAVObjectManager const &);
  void operator=(UAVObjectManager const &);
 public:
  enum JSON_EXPORT_OPTION { JSON_EXPORT_ALL, JSON_EXPORT_METADATA, JSON_EXPORT_SETTINGS, JSON_EXPORT_DATA };
  
  bool registerObject(UAVDataObject *obj);
  QList< QList<UAVObject *> > getObjects();
  QList< QList<UAVDataObject *> > getDataObjects();
  QList< QList<UAVMetaObject *> > getMetaObjects();
  UAVObject *getObject(const QString & name, quint32 instId = 0);
  UAVObject *getObject(quint32 objId, quint32 instId = 0);
  QList<UAVObject *> getObjectInstances(const QString & name);
  QList<UAVObject *> getObjectInstances(quint32 objId);
  qint32 getNumInstances(const QString & name);
  qint32 getNumInstances(quint32 objId);
  
  void toJson(QJsonObject &jsonObject, JSON_EXPORT_OPTION what = JSON_EXPORT_ALL);
  void toJson(QJsonObject &jsonObject, const QList<QString> &objectsToExport);
  void toJson(QJsonObject &jsonObject, const QList<UAVObject *> &objectsToExport);
  void fromJson(const QJsonObject &jsonObject, QList<UAVObject *> *updatedObjects = NULL);
  
 signals:
  void newObject(UAVObject *obj);
  void newInstance(UAVObject *obj);
  
 private:
  static const quint32 MAX_INSTANCES = 1000;
  
  QList< QList<UAVObject *> > objects;
  QMutex *mutex;
  
  void addObject(UAVObject *obj);
  UAVObject *getObject(const QString *name, quint32 objId, quint32 instId);
  QList<UAVObject *> getObjectInstances(const QString *name, quint32 objId);
  qint32 getNumInstances(const QString *name, quint32 objId);
};


#endif // UAVOBJECTMANAGER_H
// Local variables:
// mode: c++
// End:
