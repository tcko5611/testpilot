/**
 ******************************************************************************
 *
 * @file       serialconfig.cpp
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

#include "serialconfig.h"

#include "utils/pathutils.h"
#include <QSettings>
#include <QDebug>

/**
 * Loads a saved configuration or defaults if non exist.
 *
 */
SerialConfig::SerialConfig(QObject *parent)
  : QObject(parent), m_speed("57600")
{
  QSettings s;
  m_speed = s.value("speed", "57600").toString();
  if (m_speed.isEmpty()) {
    m_speed = "57600";
  }
}

SerialConfig::~SerialConfig()
{}

void SerialConfig::restoresettings()
{
  QSettings s;
  s.beginGroup(QLatin1String("SerialConnection"));
  QString str = (s.value(QLatin1String("speed"), tr("")).toString());
  if (str.isEmpty()) {
    m_speed = "57600";
  } else {
    m_speed = str;
  }
  s.endGroup();
}

void SerialConfig::savesettings() const
{
  QSettings s;
  s.beginGroup(QLatin1String("SerialConnection"));
  s.setValue(QLatin1String("speed"), m_speed);
  s.endGroup();
}

