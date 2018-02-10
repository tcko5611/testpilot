/**
 ******************************************************************************
 *
 * @file       serialconfig.h
 * @author     The LibrePilot Project, http://www.librepilot.org Copyright (C) 2017.
 *             The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup SerialPlugin Serial Connection Plugin
 * @{
 * @brief Impliments serial connection to the flight hardware for Telemetry
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef SERIALCONFIG_H
#define SERIALCONFIG_H
#include <QObject>
#include <QString>
/* Despite its name, this is actually a generic analog Serial
   supporting up to two rotating "needle" indicators.
 */
class SerialConfig : public QObject {
  Q_OBJECT
public:
  explicit SerialConfig(QObject *parent = 0);
  
  virtual ~SerialConfig();
  
  void savesettings() const;
  void restoresettings();

  QString speed()
  {
    return m_speed;
  }

public slots:
  void setSpeed(QString speed)
  {
    m_speed = speed;
  }
  
private:
  QString m_speed;
};

#endif // SERIALCONFIGURATION_H
// Local Variables:
// Mode: c++
// end:
