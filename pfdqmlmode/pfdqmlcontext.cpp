#include "pfdqmlcontext.h"
#if 0
#include "uavobject.h"
#include "uavobjectmanager.h"
#include "utils/stringutils.h"
#include "utils/pathutils.h"

#include "flightbatterysettings.h"
#endif
#include <QQmlContext>
#include <QDebug>
#include <QDirIterator>

const QString PfdQmlContext::CONTEXT_PROPERTY_NAME = "pfdContext";

PfdQmlContext::PfdQmlContext(QObject *parent) : QObject(parent),
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
    m_modelFile("D:/msys64/home/DELL/qt/build-testpilot-Desktop_Qt_MinGW_w64_64bit_MSYS2-Debug/share/models/multi/test_quad/test_quad_x.3ds"),
    m_modelIndex(0),
    m_backgroundImageFile("D:/msys64/home/DELL/qt/build-testpilot-Desktop_Qt_MinGW_w64_64bit_MSYS2-Debug/share/backgrounds/default_background.png")
{
}

PfdQmlContext::~PfdQmlContext()
{}

QString PfdQmlContext::speedUnit() const
{
    return m_speedUnit;
}

void PfdQmlContext::setSpeedUnit(QString unit)
{
    if (m_speedUnit != unit) {
        m_speedUnit = unit;
        emit speedUnitChanged(speedUnit());
    }
}

double PfdQmlContext::speedFactor() const
{
    return m_speedFactor;
}

void PfdQmlContext::setSpeedFactor(double factor)
{
    if (m_speedFactor != factor) {
        m_speedFactor = factor;
        emit speedFactorChanged(speedFactor());
    }
}

QString PfdQmlContext::altitudeUnit() const
{
    return m_altitudeUnit;
}

void PfdQmlContext::setAltitudeUnit(QString unit)
{
    if (m_altitudeUnit != unit) {
        m_altitudeUnit = unit;
        emit altitudeUnitChanged(altitudeUnit());
    }
}

double PfdQmlContext::altitudeFactor() const
{
    return m_altitudeFactor;
}

void PfdQmlContext::setAltitudeFactor(double factor)
{
    if (m_altitudeFactor != factor) {
        m_altitudeFactor = factor;
        emit altitudeFactorChanged(altitudeFactor());
    }
}

bool PfdQmlContext::terrainEnabled() const
{
    return m_terrainEnabled;
}

void PfdQmlContext::setTerrainEnabled(bool arg)
{
    if (m_terrainEnabled != arg) {
        m_terrainEnabled = arg;
        emit terrainEnabledChanged(terrainEnabled());
    }
}

QString PfdQmlContext::terrainFile() const
{
    return m_terrainFile;
}

void PfdQmlContext::setTerrainFile(const QString &arg)
{
    if (m_terrainFile != arg) {
        m_terrainFile = arg;
        emit terrainFileChanged(terrainFile());
    }
}

double PfdQmlContext::latitude() const
{
    return m_latitude;
}

void PfdQmlContext::setLatitude(double arg)
{
    if (m_latitude != arg) {
        m_latitude = arg;
        emit latitudeChanged(latitude());
    }
}

double PfdQmlContext::longitude() const
{
    return m_longitude;
}

void PfdQmlContext::setLongitude(double arg)
{
    if (m_longitude != arg) {
        m_longitude = arg;
        emit longitudeChanged(longitude());
    }
}

double PfdQmlContext::altitude() const
{
    return m_altitude;
}

void PfdQmlContext::setAltitude(double arg)
{
    if (m_altitude != arg) {
        m_altitude = arg;
        emit altitudeChanged(altitude());
    }
}

QDateTime PfdQmlContext::dateTime() const
{
    return m_dateTime;
}

void PfdQmlContext::setDateTime(QDateTime arg)
{
    if (m_dateTime != arg) {
        m_dateTime = arg;
        emit dateTimeChanged(dateTime());
    }
}

double PfdQmlContext::minimumAmbientLight() const
{
    return m_minAmbientLight;
}

void PfdQmlContext::setMinimumAmbientLight(double arg)
{
    if (m_minAmbientLight != arg) {
        m_minAmbientLight = arg;
        emit minimumAmbientLightChanged(minimumAmbientLight());
    }
}

QString PfdQmlContext::modelFile() const
{
    return m_modelFile;
}

void PfdQmlContext::setModelFile(const QString &arg)
{
  m_modelFile  = arg;
}

void PfdQmlContext::nextModel()
{
}

void PfdQmlContext::previousModel()
{
}

QStringList PfdQmlContext::modelFileList() const
{
    return m_modelFileList;
}

QString PfdQmlContext::backgroundImageFile() const
{
    return m_backgroundImageFile;
}

void PfdQmlContext::setBackgroundImageFile(const QString &arg)
{
  m_backgroundImageFile = arg;
}

void PfdQmlContext::resetConsumedEnergy()
{
}

void PfdQmlContext::apply(QQmlContext *context)
{
    Q_UNUSED(context);
}

void PfdQmlContext::addModelDir(QString dir)
{
    Q_UNUSED(dir);
}
