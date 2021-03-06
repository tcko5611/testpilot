/**
 ******************************************************************************
 *
 * @file       uavtalkplugin.cpp
 * @author     The LibrePilot Project, http://www.librepilot.org Copyright (C) 2016.
 *             The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVTalkPlugin UAVTalk Plugin
 * @{
 * @brief The UAVTalk protocol plugin
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
#include "uavtalkplugin.h"

#include "telemetrymanager.h"
#include "oplinkmanager.h"

#include <cores/connectionmanager.h>

UAVTalkPlugin::UAVTalkPlugin() : telemetryManager(0)
{}

UAVTalkPlugin::~UAVTalkPlugin()
{}

/**
 * Called once all the plugins which depend on us have been loaded
 */
void UAVTalkPlugin::extensionsInitialized()
{}

/**
 * Called at startup, before any plugin which depends on us is initialized
 */
bool UAVTalkPlugin::initialize(const QStringList & arguments, QString *errorString)
{
    // Done
    Q_UNUSED(arguments);
    Q_UNUSED(errorString);

    // Create TelemetryManager
    telemetryManager = new TelemetryManager();
    addAutoReleasedObject(telemetryManager);

    // Create OPLinkManager
    OPLinkManager *opLinkManager = new OPLinkManager();
    addAutoReleasedObject(opLinkManager);

    // Connect to connection manager so we get notified when the user connect to his device
    Core::ConnectionManager *cm = &Core::ConnectionManager::getInstance();
    QObject::connect(cm, SIGNAL(deviceConnected(QIODevice *)), this, SLOT(onDeviceConnect(QIODevice *)));
    QObject::connect(cm, SIGNAL(deviceAboutToDisconnect()), this, SLOT(onDeviceDisconnect()));

    return true;
}

void UAVTalkPlugin::shutdown()
{}

void UAVTalkPlugin::onDeviceConnect(QIODevice *dev)
{
    telemetryManager->start(dev);
}

void UAVTalkPlugin::onDeviceDisconnect()
{
    telemetryManager->stop();
}
