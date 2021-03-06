/**
 ******************************************************************************
 *
 * @file       coordinateconversions.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 *             Parts by Nokia Corporation (qt-info@nokia.com) Copyright (C) 2009.
 * @brief
 * @see        The GNU Public License (GPL) Version 3
 * @defgroup
 * @{
 *
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

#ifndef COORDINATECONVERSIONS_H
#define COORDINATECONVERSIONS_H

#include "opmap_global.h"
#include "math.h"

namespace Utils {
class OPMAP_EXPORT CoordinateConversions {
public:
    CoordinateConversions();
    static int NED2LLA_HomeECEF(double BaseECEFcm[3], double NED[3], double position[3]);
    static int NED2LLA_HomeLLA(double LLA[3], double NED[3], double position[3]);
    static void RneFromLLA(double LLA[3], float Rne[3][3]);
    static void LLA2ECEF(double LLA[3], double ECEF[3]);
    static int ECEF2LLA(double ECEF[3], double LLA[3]);
    static void LLA2Base(double LLA[3], double BaseECEF[3], float Rne[3][3], float NED[3]);
    static void Quaternion2RPY(const float q[4], float rpy[3]);
    static void RPY2Quaternion(const float rpy[3], float q[4]);
    static void Quaternion2R(const float q[4], float Rbe[3][3]);
    static void R2Quaternion(float const Rbe[3][3], float q[4]);
};
}

#endif /* COORDINATECONVERSIONS_H */
