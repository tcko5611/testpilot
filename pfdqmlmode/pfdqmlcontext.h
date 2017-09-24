#ifndef PFDQMLCONTEXT_H_
#define PFDQMLCONTEXT_H_
#if 0
#include "pfdqml.h"
#include "pfdqmlgadgetconfiguration.h"
#endif
#include <QObject>
#include <QDateTime>
class QQmlContext;
class QSettings;

class PfdQmlContext : public QObject {
    Q_OBJECT Q_PROPERTY(QString speedUnit READ speedUnit WRITE setSpeedUnit NOTIFY speedUnitChanged)
    Q_PROPERTY(double speedFactor READ speedFactor WRITE setSpeedFactor NOTIFY speedFactorChanged)
    Q_PROPERTY(QString altitudeUnit READ altitudeUnit WRITE setAltitudeUnit NOTIFY altitudeUnitChanged)
    Q_PROPERTY(double altitudeFactor READ altitudeFactor WRITE setAltitudeFactor NOTIFY altitudeFactorChanged)

    // terrain
    Q_PROPERTY(bool terrainEnabled READ terrainEnabled WRITE setTerrainEnabled NOTIFY terrainEnabledChanged)
    Q_PROPERTY(QString terrainFile READ terrainFile WRITE setTerrainFile NOTIFY terrainFileChanged)

    Q_PROPERTY(double latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
    Q_PROPERTY(double longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)
    Q_PROPERTY(double altitude READ altitude WRITE setAltitude NOTIFY altitudeChanged)

    Q_PROPERTY(QDateTime dateTime READ dateTime WRITE setDateTime NOTIFY dateTimeChanged)
    Q_PROPERTY(double minimumAmbientLight READ minimumAmbientLight WRITE setMinimumAmbientLight NOTIFY minimumAmbientLightChanged)

    // model
    Q_PROPERTY(QString modelFile READ modelFile NOTIFY modelFileChanged)
    Q_PROPERTY(QStringList modelFileList READ modelFileList CONSTANT FINAL)

    // background
    Q_PROPERTY(QString backgroundImageFile READ backgroundImageFile WRITE setBackgroundImageFile NOTIFY backgroundImageFileChanged)

public:
    PfdQmlContext(QObject *parent = 0);
    virtual ~PfdQmlContext();

    QString speedUnit() const;
    void setSpeedUnit(QString unit);
    double speedFactor() const;
    void setSpeedFactor(double factor);
    QString altitudeUnit() const;
    void setAltitudeUnit(QString unit);
    double altitudeFactor() const;
    void setAltitudeFactor(double factor);

    bool terrainEnabled() const;
    void setTerrainEnabled(bool arg);
    QString terrainFile() const;
    void setTerrainFile(const QString &arg);

    double latitude() const;
    void setLatitude(double arg);
    double longitude() const;
    void setLongitude(double arg);
    double altitude() const;
    void setAltitude(double arg);

    QDateTime dateTime() const;
    void setDateTime(QDateTime arg);
    double minimumAmbientLight() const;
    void setMinimumAmbientLight(double arg);

    // model
    QString modelFile() const;
    void setModelFile(const QString &arg);
    QStringList modelFileList() const;
    Q_INVOKABLE void nextModel();
    Q_INVOKABLE void previousModel();

    // background
    QString backgroundImageFile() const;
    void setBackgroundImageFile(const QString &arg);

    Q_INVOKABLE void resetConsumedEnergy();

    void saveState(QSettings *);
    void restoreState(QSettings *);

    void apply(QQmlContext *context);

signals:
    void speedUnitChanged(QString arg);
    void speedFactorChanged(double arg);
    void altitudeUnitChanged(QString arg);
    void altitudeFactorChanged(double arg);

    void terrainEnabledChanged(bool arg);
    void terrainFileChanged(QString arg);

    void latitudeChanged(double arg);
    void longitudeChanged(double arg);
    void altitudeChanged(double arg);

    void dateTimeChanged(QDateTime arge);
    void minimumAmbientLightChanged(double arg);

    void modelFileChanged(QString arg);
    void backgroundImageFileChanged(QString arg);

private:
    // constants
    static const QString CONTEXT_PROPERTY_NAME;

    QString m_speedUnit;
    double m_speedFactor;
    QString m_altitudeUnit;
    double m_altitudeFactor;

    bool m_terrainEnabled;
    QString m_terrainFile;

    double m_latitude;
    double m_longitude;
    double m_altitude;

    QDateTime m_dateTime;
    double m_minAmbientLight;

    QString m_modelFile;
    int m_modelIndex;
    QStringList m_modelFileList;

    QString m_backgroundImageFile;

    void addModelDir(QString dir);
};
#endif /* PFDQMLCONTEXT_H_ */
