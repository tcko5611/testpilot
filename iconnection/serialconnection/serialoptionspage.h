/**
 ******************************************************************************
 *
 * @file       serialpluginoptionspage.h
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

#ifndef SERIALOPTIONSPAGE_H
#define SERIALOPTIONSPAGE_H

#include <QObject>
#include <QString>

class SerialConfig;

namespace Ui {
class SerialOptionsPage;
}

class SerialOptionsPage : public QObject {
    Q_OBJECT
public:
    explicit SerialOptionsPage(SerialConfig *config, QObject *parent = 0);

    QString id() const
    {
      return QLatin1String("settings");
    }
    QString trName() const
    {
      return tr("settings");
    }
    QString category() const
    {
      return "Telemetry - Serial";
    }
    QString trCategory() const
    {
      return "Serial Telemetry";
    }
    QWidget *createPage(QWidget *parent = 0);
    void apply();
    void finish();
    void setComList(QStringList allCom);
signals:
    void availableDevChanged();

private:
    Ui::SerialOptionsPage *m_page;
    SerialConfig *m_config;
};

#endif // SERIALOPTIONSPAGE_H
// Local Variables:
// Mode: c++
// End:
