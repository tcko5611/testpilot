/**
 ******************************************************************************
 *
 * @file       utils_global.h
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

#ifndef INTERNALS_GLOBAL_H
#define INTERNALS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(INTERNALS_LIB)
#  define INTERNALS_EXPORT Q_DECL_EXPORT
#elif  defined(INTERNALS_STATIC_LIB) // Abuse single files for manual tests
#  define INTERNALS_EXPORT
#else
#  define INTERNALS_EXPORT Q_DECL_IMPORT
#endif

#endif // INTERNALS_GLOBAL_H
