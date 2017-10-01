#ifndef ATTITUDESTATE_H
#define ATTITUDESTATE_H
#include <QObject>
class QMutex;

class AttitudeStateConstants : public QObject {
  Q_OBJECT
public:
  enum Enum {  };
  Q_ENUMS(Enum) // TODO switch to Q_ENUM once on Qt 5.5
};



class AttitudeState : public QObject
{
  Q_OBJECT
  Q_PROPERTY(float q1 READ q1 WRITE setQ1 NOTIFY q1Changed)
  Q_PROPERTY(float q2 READ q2 WRITE setQ2 NOTIFY q2Changed)
  Q_PROPERTY(float q3 READ q3 WRITE setQ3 NOTIFY q3Changed)
  Q_PROPERTY(float q4 READ q4 WRITE setQ4 NOTIFY q4Changed)
  Q_PROPERTY(float roll READ roll WRITE setRoll NOTIFY rollChanged)
  Q_PROPERTY(float pitch READ pitch WRITE setPitch NOTIFY pitchChanged)
  Q_PROPERTY(float yaw READ yaw WRITE setYaw NOTIFY yawChanged)
  Q_PROPERTY(float navYaw READ navYaw WRITE setNavYaw NOTIFY navYawChanged)
  
 public:
  // Field structure
  typedef struct {
    float q1;
    float q2;
    float q3;
    float q4;
    float Roll;
    float Pitch;
    float Yaw;
    float NavYaw;
  } __attribute__((packed)) DataFields;
  
  // Constants
  static const quint32 OBJID = 0x7421C7BA;
  static const QString NAME;
  static const QString DESCRIPTION;
  static const QString CATEGORY;
  static const bool ISSINGLEINST = 1;
  static const bool ISSETTINGS = 0;
  static const quint32 NUMBYTES = sizeof(DataFields);
  
  // Functions
  AttitudeState();
  
  DataFields getData();
  void setData(const DataFields& data, bool emitUpdateEvents = true);
  
  static void registerQMLTypes();

  float q1() const;
  float q2() const;
  float q3() const;
  float q4() const;
  float roll() const;
  float pitch() const;
  float yaw() const;
  float navYaw() const;

 public slots:
  void setQ1(const float value);
  void setQ2(const float value);
  void setQ3(const float value);
  void setQ4(const float value);
  void setRoll(const float value);
  void setPitch(const float value);
  void setYaw(const float value);
  void setNavYaw(const float value);

 signals:
  void q1Changed(const float value);
  void q2Changed(const float value);
  void q3Changed(const float value);
  void q4Changed(const float value);
  void rollChanged(const float value);
  void pitchChanged(const float value);
  void yawChanged(const float value);
  void navYawChanged(const float value);

 private slots:
  void emitNotifications();

 private:
  DataFields data_;
  void setDefaultFieldValues();
  QMutex *mutex;
};

#endif // ATTITUDESTATE_H
// Local Variables:
// mode: c++
// End:
