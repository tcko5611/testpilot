/**
 ******************************************************************************
 *
 * @file       attitudestate.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *
 * @note       Object definition file: attitudestate.xml.
 *             This is an automatically generated file.
 *             DO NOT modify manually.
 *
 * @brief      The UAVUObjects GCS plugin
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

#include "attitudestate.h"

#include <QtQml>
#include <QMutex>
const QString AttitudeState::NAME = QString("AttitudeState");
const QString AttitudeState::DESCRIPTION = QString("The updated Attitude estimation from @ref StateEstimationModule.");
const QString AttitudeState::CATEGORY = QString("State");

/**
 * Constructor
 */
AttitudeState::AttitudeState()
{
    mutex = new QMutex(QMutex::Recursive);
}


/**
 * Get the object data fields
 */
AttitudeState::DataFields AttitudeState::getData()
{
    QMutexLocker locker(mutex);
    return data_;
}

/**
 * Set the object data fields and (optionaly) emit object update events
 */
void AttitudeState::setData(const DataFields& data, bool emitUpdateEvents)
{
    QMutexLocker locker(mutex);
    // Get metadata
    // Update object if the access mode permits
    this->data_ = data;
    if (emitUpdateEvents) {
    }
}

void AttitudeState::emitNotifications()
{
    emit q1Changed(q1());
    emit q2Changed(q2());
    emit q3Changed(q3());
    emit q4Changed(q4());
    emit rollChanged(roll());
    emit pitchChanged(pitch());
    emit yawChanged(yaw());
    emit navYawChanged(navYaw());
}

/**
 * Static function to register QML types.
 */
void AttitudeState::registerQMLTypes() {
    qmlRegisterType<AttitudeState>("UAVTalk.AttitudeState", 1, 0, "AttitudeState");
    qmlRegisterType<AttitudeStateConstants>("UAVTalk.AttitudeState", 1, 0, "AttitudeStateConstants");

}

float AttitudeState::q1() const
{
   QMutexLocker locker(mutex);
   return static_cast<float>(data_.q1);
}
void AttitudeState::setQ1(const float value)
{
   mutex->lock();
   bool changed = (data_.q1 != static_cast<float>(value));
   data_.q1 = static_cast<float>(value);
   mutex->unlock();
   if (changed) { emit q1Changed(value); }
}

float AttitudeState::q2() const
{
   QMutexLocker locker(mutex);
   return static_cast<float>(data_.q2);
}
void AttitudeState::setQ2(const float value)
{
   mutex->lock();
   bool changed = (data_.q2 != static_cast<float>(value));
   data_.q2 = static_cast<float>(value);
   mutex->unlock();
   if (changed) { emit q2Changed(value); }
}

float AttitudeState::q3() const
{
   QMutexLocker locker(mutex);
   return static_cast<float>(data_.q3);
}
void AttitudeState::setQ3(const float value)
{
   mutex->lock();
   bool changed = (data_.q3 != static_cast<float>(value));
   data_.q3 = static_cast<float>(value);
   mutex->unlock();
   if (changed) { emit q3Changed(value); }
}

float AttitudeState::q4() const
{
   QMutexLocker locker(mutex);
   return static_cast<float>(data_.q4);
}
void AttitudeState::setQ4(const float value)
{
   mutex->lock();
   bool changed = (data_.q4 != static_cast<float>(value));
   data_.q4 = static_cast<float>(value);
   mutex->unlock();
   if (changed) { emit q4Changed(value); }
}

float AttitudeState::roll() const
{
   QMutexLocker locker(mutex);
   return static_cast<float>(data_.Roll);
}
void AttitudeState::setRoll(const float value)
{
   mutex->lock();
   bool changed = (data_.Roll != static_cast<float>(value));
   data_.Roll = static_cast<float>(value);
   mutex->unlock();
   if (changed) { emit rollChanged(value); }
}

float AttitudeState::pitch() const
{
   QMutexLocker locker(mutex);
   return static_cast<float>(data_.Pitch);
}
void AttitudeState::setPitch(const float value)
{
   mutex->lock();
   bool changed = (data_.Pitch != static_cast<float>(value));
   data_.Pitch = static_cast<float>(value);
   mutex->unlock();
   if (changed) { emit pitchChanged(value); }
}

float AttitudeState::yaw() const
{
   QMutexLocker locker(mutex);
   return static_cast<float>(data_.Yaw);
}
void AttitudeState::setYaw(const float value)
{
   mutex->lock();
   bool changed = (data_.Yaw != static_cast<float>(value));
   data_.Yaw = static_cast<float>(value);
   mutex->unlock();
   if (changed) { emit yawChanged(value); }
}

float AttitudeState::navYaw() const
{
   QMutexLocker locker(mutex);
   return static_cast<float>(data_.NavYaw);
}
void AttitudeState::setNavYaw(const float value)
{
   mutex->lock();
   bool changed = (data_.NavYaw != static_cast<float>(value));
   data_.NavYaw = static_cast<float>(value);
   mutex->unlock();
   if (changed) { emit navYawChanged(value); }
}


