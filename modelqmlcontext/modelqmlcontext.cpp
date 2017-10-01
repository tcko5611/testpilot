#include "modelqmlcontext.h"
#include <QQmlContext>
#include <QDebug>
#include <QDirIterator>

ModelQmlContext::ModelQmlContext(QObject *parent) : QObject(parent),
						    m_speedUnit("m/s"),
						    m_speedFactor(1.0),
						    m_altitudeUnit("m"),
						    m_altitudeFactor(1.0),
						    m_terrainEnabled(false),
						    m_terrainFile(""),
						    m_latitude(39.657380),
						    m_longitude(19.805158),
						    m_altitude(100),
						    m_dateTime(QDateTime()),
						    m_minAmbientLight(0.03),
                            m_modelFile(""),
						    m_modelIndex(0),
                            m_backgroundImageFile("")
{
}

ModelQmlContext::~ModelQmlContext()
{}

QString ModelQmlContext::speedUnit() const
{
  return m_speedUnit;
}

void ModelQmlContext::setSpeedUnit(QString unit)
{
  if (m_speedUnit != unit) {
    m_speedUnit = unit;
    emit speedUnitChanged(speedUnit());
  }
}

double ModelQmlContext::speedFactor() const
{
  return m_speedFactor;
}

void ModelQmlContext::setSpeedFactor(double factor)
{
  if (m_speedFactor != factor) {
    m_speedFactor = factor;
    emit speedFactorChanged(speedFactor());
  }
}

QString ModelQmlContext::altitudeUnit() const
{
  return m_altitudeUnit;
}

void ModelQmlContext::setAltitudeUnit(QString unit)
{
  if (m_altitudeUnit != unit) {
    m_altitudeUnit = unit;
    emit altitudeUnitChanged(altitudeUnit());
  }
}

double ModelQmlContext::altitudeFactor() const
{
  return m_altitudeFactor;
}

void ModelQmlContext::setAltitudeFactor(double factor)
{
  if (m_altitudeFactor != factor) {
    m_altitudeFactor = factor;
    emit altitudeFactorChanged(altitudeFactor());
  }
}

bool ModelQmlContext::terrainEnabled() const
{
  return m_terrainEnabled;
}

void ModelQmlContext::setTerrainEnabled(bool arg)
{
  if (m_terrainEnabled != arg) {
    m_terrainEnabled = arg;
    emit terrainEnabledChanged(terrainEnabled());
  }
}

QString ModelQmlContext::terrainFile() const
{
  return m_terrainFile;
}

void ModelQmlContext::setTerrainFile(const QString &arg)
{
  if (m_terrainFile != arg) {
    m_terrainFile = arg;
    emit terrainFileChanged(terrainFile());
  }
}

double ModelQmlContext::latitude() const
{
  return m_latitude;
}

void ModelQmlContext::setLatitude(double arg)
{
  if (m_latitude != arg) {
    m_latitude = arg;
    emit latitudeChanged(latitude());
  }
}

double ModelQmlContext::longitude() const
{
  return m_longitude;
}

void ModelQmlContext::setLongitude(double arg)
{
  if (m_longitude != arg) {
    m_longitude = arg;
    emit longitudeChanged(longitude());
  }
}

double ModelQmlContext::altitude() const
{
  return m_altitude;
}

void ModelQmlContext::setAltitude(double arg)
{
  if (m_altitude != arg) {
    m_altitude = arg;
    emit altitudeChanged(altitude());
  }
}

QDateTime ModelQmlContext::dateTime() const
{
  return m_dateTime;
}

void ModelQmlContext::setDateTime(QDateTime arg)
{
  if (m_dateTime != arg) {
    m_dateTime = arg;
    emit dateTimeChanged(dateTime());
  }
}

double ModelQmlContext::minimumAmbientLight() const
{
  return m_minAmbientLight;
}

void ModelQmlContext::setMinimumAmbientLight(double arg)
{
  if (m_minAmbientLight != arg) {
    m_minAmbientLight = arg;
    emit minimumAmbientLightChanged(minimumAmbientLight());
  }
}

QString ModelQmlContext::modelFile() const
{
  return m_modelFile;
}

void ModelQmlContext::setModelFile(const QString &arg)
{
  m_modelFile  = arg;
}

void ModelQmlContext::nextModel()
{
}

void ModelQmlContext::previousModel()
{
}

QStringList ModelQmlContext::modelFileList() const
{
  return m_modelFileList;
}

QString ModelQmlContext::backgroundImageFile() const
{
  return m_backgroundImageFile;
}

void ModelQmlContext::setBackgroundImageFile(const QString &arg)
{
  m_backgroundImageFile = arg;
}

void ModelQmlContext::resetConsumedEnergy()
{
}

void ModelQmlContext::apply(QQmlContext *context)
{
  Q_UNUSED(context);
}

void ModelQmlContext::addModelDir(QString dir)
{
  Q_UNUSED(dir);
}
