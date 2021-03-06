/**
 ******************************************************************************
 *
 * @file       ioptionspage.h
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

#ifndef IOPTIONSPAGE_H
#define IOPTIONSPAGE_H

#include "utils_global.h"

#include <QtCore/QObject>
#include <QIcon>

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE

namespace Core {
class QTCREATOR_UTILS_EXPORT IOptionsPage : public QObject {
	Q_OBJECT

 public:
	IOptionsPage(QObject *parent = 0) :
	QObject(parent),
        m_icon(QIcon()) {}
    virtual ~IOptionsPage() {}

    void setIcon(QIcon icon)
    {
        m_icon = icon;
    }

    QIcon icon()
    {
        return m_icon;
    }

    /*  gadget options pages can leave these 4 functions as is,
        since they are decorated by UAVGadgetOptionsPageDecorator,
        all other options pages must override these */
    virtual QString id() const
    {
        return "";
    };

    virtual QString trName() const
    {
        return "";
    };

    virtual QString category() const
    {
        return "DefaultCategory";
    };

    virtual QString trCategory() const
    {
        return "DefaultCategory";
    };

    virtual QWidget *createPage(QWidget *parent) = 0;

    virtual void apply()  = 0;
    virtual void finish() = 0;

public slots:
    virtual void updateState()
    {};

private:
    QIcon m_icon;
};
} // namespace Core

#endif // IOPTIONSPAGE_H
// Local variables:
// mode: c++
// End:
