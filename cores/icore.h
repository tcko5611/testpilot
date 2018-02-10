/**
 ******************************************************************************
 *
 * @file       icore.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 *             Parts by Nokia Corporation (qt-info@nokia.com) Copyright (C) 2009.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup CorePlugin Core Plugin
 * @{
 * @brief The Core GCS plugin
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

#ifndef ICORE_H
#define ICORE_H

#include "cores_global.h"

#include <QtCore/QObject>
#include <QSettings>

QT_BEGIN_NAMESPACE

class QSettings;
template <class T> class QList;
QT_END_NAMESPACE
class MainWindow;

namespace Core {
  class CORES_EXPORT ICore : public QObject {
    Q_OBJECT
    
  public:
    // sigleton pattern
    static ICore& getInstance() {
      if (instance == NULL) {
	QMutexLocker locker(&smutex);
	if (instance == NULL) {
	  instance = new ICore();
	}
      }
      return *instance;
    }
  private:
    ICore() {}
    virtual ~ICore() {}
    
  public:
    
    QString resourcePath() const;
    
    virtual void openFiles(const QStringList &fileNames);
    
  private:
    static ICore *instance;
    static QMutex smutex;
  };
} // namespace Core

#endif // ICORE_H
// Local Variables:
// mode: c++
// End:
