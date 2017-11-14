find_package(Qt5Core)
find_package(Qt5Qml)
set(CMAKE_AUTOMOC OFF)
set(UAVObjectsInit "${CMAKE_CURRENT_BINARY_DIR}/uavobjectsinit.cpp")
add_custom_command( 
  OUTPUT  ${UAVObjectsInit} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})

set(accelgyrosettings "${CMAKE_CURRENT_BINARY_DIR}/accelgyrosettings.cpp")
set(accelgyrosettingsH "${CMAKE_CURRENT_BINARY_DIR}/accelgyrosettings.h")
add_custom_command( 
  OUTPUT  ${accelgyrosettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${accelgyrosettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(accelsensor "${CMAKE_CURRENT_BINARY_DIR}/accelsensor.cpp")
set(accelsensorH "${CMAKE_CURRENT_BINARY_DIR}/accelsensor.h")
add_custom_command( 
  OUTPUT  ${accelsensor} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${accelsensorH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(accelstate "${CMAKE_CURRENT_BINARY_DIR}/accelstate.cpp")
set(accelstateH "${CMAKE_CURRENT_BINARY_DIR}/accelstate.h")
add_custom_command( 
  OUTPUT  ${accelstate} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${accelstateH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(accessorydesired "${CMAKE_CURRENT_BINARY_DIR}/accessorydesired.cpp")
set(accessorydesiredH "${CMAKE_CURRENT_BINARY_DIR}/accessorydesired.h")
add_custom_command( 
  OUTPUT  ${accessorydesired} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${accessorydesiredH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(actuatorcommand "${CMAKE_CURRENT_BINARY_DIR}/actuatorcommand.cpp")
set(actuatorcommandH "${CMAKE_CURRENT_BINARY_DIR}/actuatorcommand.h")
add_custom_command( 
  OUTPUT  ${actuatorcommand} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${actuatorcommandH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(actuatordesired "${CMAKE_CURRENT_BINARY_DIR}/actuatordesired.cpp")
set(actuatordesiredH "${CMAKE_CURRENT_BINARY_DIR}/actuatordesired.h")
add_custom_command( 
  OUTPUT  ${actuatordesired} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${actuatordesiredH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(actuatorsettings "${CMAKE_CURRENT_BINARY_DIR}/actuatorsettings.cpp")
set(actuatorsettingsH "${CMAKE_CURRENT_BINARY_DIR}/actuatorsettings.h")
add_custom_command( 
  OUTPUT  ${actuatorsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${actuatorsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(airspeedsensor "${CMAKE_CURRENT_BINARY_DIR}/airspeedsensor.cpp")
set(airspeedsensorH "${CMAKE_CURRENT_BINARY_DIR}/airspeedsensor.h")
add_custom_command( 
  OUTPUT  ${airspeedsensor} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${airspeedsensorH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(airspeedsettings "${CMAKE_CURRENT_BINARY_DIR}/airspeedsettings.cpp")
set(airspeedsettingsH "${CMAKE_CURRENT_BINARY_DIR}/airspeedsettings.h")
add_custom_command( 
  OUTPUT  ${airspeedsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${airspeedsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(airspeedstate "${CMAKE_CURRENT_BINARY_DIR}/airspeedstate.cpp")
set(airspeedstateH "${CMAKE_CURRENT_BINARY_DIR}/airspeedstate.h")
add_custom_command( 
  OUTPUT  ${airspeedstate} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${airspeedstateH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(altitudefiltersettings "${CMAKE_CURRENT_BINARY_DIR}/altitudefiltersettings.cpp")
set(altitudefiltersettingsH "${CMAKE_CURRENT_BINARY_DIR}/altitudefiltersettings.h")
add_custom_command( 
  OUTPUT  ${altitudefiltersettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${altitudefiltersettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(altitudeholdsettings "${CMAKE_CURRENT_BINARY_DIR}/altitudeholdsettings.cpp")
set(altitudeholdsettingsH "${CMAKE_CURRENT_BINARY_DIR}/altitudeholdsettings.h")
add_custom_command( 
  OUTPUT  ${altitudeholdsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${altitudeholdsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(altitudeholdstatus "${CMAKE_CURRENT_BINARY_DIR}/altitudeholdstatus.cpp")
set(altitudeholdstatusH "${CMAKE_CURRENT_BINARY_DIR}/altitudeholdstatus.h")
add_custom_command( 
  OUTPUT  ${altitudeholdstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${altitudeholdstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(attitudesettings "${CMAKE_CURRENT_BINARY_DIR}/attitudesettings.cpp")
set(attitudesettingsH "${CMAKE_CURRENT_BINARY_DIR}/attitudesettings.h")
add_custom_command( 
  OUTPUT  ${attitudesettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${attitudesettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(attitudesimulated "${CMAKE_CURRENT_BINARY_DIR}/attitudesimulated.cpp")
set(attitudesimulatedH "${CMAKE_CURRENT_BINARY_DIR}/attitudesimulated.h")
add_custom_command( 
  OUTPUT  ${attitudesimulated} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${attitudesimulatedH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(attitudestate "${CMAKE_CURRENT_BINARY_DIR}/attitudestate.cpp")
set(attitudestateH "${CMAKE_CURRENT_BINARY_DIR}/attitudestate.h")
add_custom_command( 
  OUTPUT  ${attitudestate} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${attitudestateH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(auxmagsensor "${CMAKE_CURRENT_BINARY_DIR}/auxmagsensor.cpp")
set(auxmagsensorH "${CMAKE_CURRENT_BINARY_DIR}/auxmagsensor.h")
add_custom_command( 
  OUTPUT  ${auxmagsensor} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${auxmagsensorH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(auxmagsettings "${CMAKE_CURRENT_BINARY_DIR}/auxmagsettings.cpp")
set(auxmagsettingsH "${CMAKE_CURRENT_BINARY_DIR}/auxmagsettings.h")
add_custom_command( 
  OUTPUT  ${auxmagsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${auxmagsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(barosensor "${CMAKE_CURRENT_BINARY_DIR}/barosensor.cpp")
set(barosensorH "${CMAKE_CURRENT_BINARY_DIR}/barosensor.h")
add_custom_command( 
  OUTPUT  ${barosensor} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${barosensorH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(callbackinfo "${CMAKE_CURRENT_BINARY_DIR}/callbackinfo.cpp")
set(callbackinfoH "${CMAKE_CURRENT_BINARY_DIR}/callbackinfo.h")
add_custom_command( 
  OUTPUT  ${callbackinfo} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${callbackinfoH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(cameracontrolactivity "${CMAKE_CURRENT_BINARY_DIR}/cameracontrolactivity.cpp")
set(cameracontrolactivityH "${CMAKE_CURRENT_BINARY_DIR}/cameracontrolactivity.h")
add_custom_command( 
  OUTPUT  ${cameracontrolactivity} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${cameracontrolactivityH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(cameracontrolsettings "${CMAKE_CURRENT_BINARY_DIR}/cameracontrolsettings.cpp")
set(cameracontrolsettingsH "${CMAKE_CURRENT_BINARY_DIR}/cameracontrolsettings.h")
add_custom_command( 
  OUTPUT  ${cameracontrolsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${cameracontrolsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(cameradesired "${CMAKE_CURRENT_BINARY_DIR}/cameradesired.cpp")
set(cameradesiredH "${CMAKE_CURRENT_BINARY_DIR}/cameradesired.h")
add_custom_command( 
  OUTPUT  ${cameradesired} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${cameradesiredH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(camerastabsettings "${CMAKE_CURRENT_BINARY_DIR}/camerastabsettings.cpp")
set(camerastabsettingsH "${CMAKE_CURRENT_BINARY_DIR}/camerastabsettings.h")
add_custom_command( 
  OUTPUT  ${camerastabsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${camerastabsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(debuglogcontrol "${CMAKE_CURRENT_BINARY_DIR}/debuglogcontrol.cpp")
set(debuglogcontrolH "${CMAKE_CURRENT_BINARY_DIR}/debuglogcontrol.h")
add_custom_command( 
  OUTPUT  ${debuglogcontrol} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${debuglogcontrolH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(debuglogentry "${CMAKE_CURRENT_BINARY_DIR}/debuglogentry.cpp")
set(debuglogentryH "${CMAKE_CURRENT_BINARY_DIR}/debuglogentry.h")
add_custom_command( 
  OUTPUT  ${debuglogentry} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${debuglogentryH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(debuglogsettings "${CMAKE_CURRENT_BINARY_DIR}/debuglogsettings.cpp")
set(debuglogsettingsH "${CMAKE_CURRENT_BINARY_DIR}/debuglogsettings.h")
add_custom_command( 
  OUTPUT  ${debuglogsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${debuglogsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(debuglogstatus "${CMAKE_CURRENT_BINARY_DIR}/debuglogstatus.cpp")
set(debuglogstatusH "${CMAKE_CURRENT_BINARY_DIR}/debuglogstatus.h")
add_custom_command( 
  OUTPUT  ${debuglogstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${debuglogstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(ekfconfiguration "${CMAKE_CURRENT_BINARY_DIR}/ekfconfiguration.cpp")
set(ekfconfigurationH "${CMAKE_CURRENT_BINARY_DIR}/ekfconfiguration.h")
add_custom_command( 
  OUTPUT  ${ekfconfiguration} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${ekfconfigurationH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(ekfstatevariance "${CMAKE_CURRENT_BINARY_DIR}/ekfstatevariance.cpp")
set(ekfstatevarianceH "${CMAKE_CURRENT_BINARY_DIR}/ekfstatevariance.h")
add_custom_command( 
  OUTPUT  ${ekfstatevariance} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${ekfstatevarianceH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(faultsettings "${CMAKE_CURRENT_BINARY_DIR}/faultsettings.cpp")
set(faultsettingsH "${CMAKE_CURRENT_BINARY_DIR}/faultsettings.h")
add_custom_command( 
  OUTPUT  ${faultsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${faultsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(firmwareiapobj "${CMAKE_CURRENT_BINARY_DIR}/firmwareiapobj.cpp")
set(firmwareiapobjH "${CMAKE_CURRENT_BINARY_DIR}/firmwareiapobj.h")
add_custom_command( 
  OUTPUT  ${firmwareiapobj} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${firmwareiapobjH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(fixedwingpathfollowersettings "${CMAKE_CURRENT_BINARY_DIR}/fixedwingpathfollowersettings.cpp")
set(fixedwingpathfollowersettingsH "${CMAKE_CURRENT_BINARY_DIR}/fixedwingpathfollowersettings.h")
add_custom_command( 
  OUTPUT  ${fixedwingpathfollowersettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${fixedwingpathfollowersettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(fixedwingpathfollowerstatus "${CMAKE_CURRENT_BINARY_DIR}/fixedwingpathfollowerstatus.cpp")
set(fixedwingpathfollowerstatusH "${CMAKE_CURRENT_BINARY_DIR}/fixedwingpathfollowerstatus.h")
add_custom_command( 
  OUTPUT  ${fixedwingpathfollowerstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${fixedwingpathfollowerstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(flightbatterysettings "${CMAKE_CURRENT_BINARY_DIR}/flightbatterysettings.cpp")
set(flightbatterysettingsH "${CMAKE_CURRENT_BINARY_DIR}/flightbatterysettings.h")
add_custom_command( 
  OUTPUT  ${flightbatterysettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${flightbatterysettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(flightbatterystate "${CMAKE_CURRENT_BINARY_DIR}/flightbatterystate.cpp")
set(flightbatterystateH "${CMAKE_CURRENT_BINARY_DIR}/flightbatterystate.h")
add_custom_command( 
  OUTPUT  ${flightbatterystate} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${flightbatterystateH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(flightmodesettings "${CMAKE_CURRENT_BINARY_DIR}/flightmodesettings.cpp")
set(flightmodesettingsH "${CMAKE_CURRENT_BINARY_DIR}/flightmodesettings.h")
add_custom_command( 
  OUTPUT  ${flightmodesettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${flightmodesettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(flightplancontrol "${CMAKE_CURRENT_BINARY_DIR}/flightplancontrol.cpp")
set(flightplancontrolH "${CMAKE_CURRENT_BINARY_DIR}/flightplancontrol.h")
add_custom_command( 
  OUTPUT  ${flightplancontrol} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${flightplancontrolH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(flightplansettings "${CMAKE_CURRENT_BINARY_DIR}/flightplansettings.cpp")
set(flightplansettingsH "${CMAKE_CURRENT_BINARY_DIR}/flightplansettings.h")
add_custom_command( 
  OUTPUT  ${flightplansettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${flightplansettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(flightplanstatus "${CMAKE_CURRENT_BINARY_DIR}/flightplanstatus.cpp")
set(flightplanstatusH "${CMAKE_CURRENT_BINARY_DIR}/flightplanstatus.h")
add_custom_command( 
  OUTPUT  ${flightplanstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${flightplanstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(flightstatus "${CMAKE_CURRENT_BINARY_DIR}/flightstatus.cpp")
set(flightstatusH "${CMAKE_CURRENT_BINARY_DIR}/flightstatus.h")
add_custom_command( 
  OUTPUT  ${flightstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${flightstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(flighttelemetrystats "${CMAKE_CURRENT_BINARY_DIR}/flighttelemetrystats.cpp")
set(flighttelemetrystatsH "${CMAKE_CURRENT_BINARY_DIR}/flighttelemetrystats.h")
add_custom_command( 
  OUTPUT  ${flighttelemetrystats} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${flighttelemetrystatsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(gcsreceiver "${CMAKE_CURRENT_BINARY_DIR}/gcsreceiver.cpp")
set(gcsreceiverH "${CMAKE_CURRENT_BINARY_DIR}/gcsreceiver.h")
add_custom_command( 
  OUTPUT  ${gcsreceiver} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${gcsreceiverH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(gcstelemetrystats "${CMAKE_CURRENT_BINARY_DIR}/gcstelemetrystats.cpp")
set(gcstelemetrystatsH "${CMAKE_CURRENT_BINARY_DIR}/gcstelemetrystats.h")
add_custom_command( 
  OUTPUT  ${gcstelemetrystats} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${gcstelemetrystatsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(gpsextendedstatus "${CMAKE_CURRENT_BINARY_DIR}/gpsextendedstatus.cpp")
set(gpsextendedstatusH "${CMAKE_CURRENT_BINARY_DIR}/gpsextendedstatus.h")
add_custom_command( 
  OUTPUT  ${gpsextendedstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${gpsextendedstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(gpspositionsensor "${CMAKE_CURRENT_BINARY_DIR}/gpspositionsensor.cpp")
set(gpspositionsensorH "${CMAKE_CURRENT_BINARY_DIR}/gpspositionsensor.h")
add_custom_command( 
  OUTPUT  ${gpspositionsensor} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${gpspositionsensorH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(gpssatellites "${CMAKE_CURRENT_BINARY_DIR}/gpssatellites.cpp")
set(gpssatellitesH "${CMAKE_CURRENT_BINARY_DIR}/gpssatellites.h")
add_custom_command( 
  OUTPUT  ${gpssatellites} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${gpssatellitesH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(gpssettings "${CMAKE_CURRENT_BINARY_DIR}/gpssettings.cpp")
set(gpssettingsH "${CMAKE_CURRENT_BINARY_DIR}/gpssettings.h")
add_custom_command( 
  OUTPUT  ${gpssettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${gpssettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(gpstime "${CMAKE_CURRENT_BINARY_DIR}/gpstime.cpp")
set(gpstimeH "${CMAKE_CURRENT_BINARY_DIR}/gpstime.h")
add_custom_command( 
  OUTPUT  ${gpstime} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${gpstimeH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(gpsvelocitysensor "${CMAKE_CURRENT_BINARY_DIR}/gpsvelocitysensor.cpp")
set(gpsvelocitysensorH "${CMAKE_CURRENT_BINARY_DIR}/gpsvelocitysensor.h")
add_custom_command( 
  OUTPUT  ${gpsvelocitysensor} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${gpsvelocitysensorH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(groundpathfollowersettings "${CMAKE_CURRENT_BINARY_DIR}/groundpathfollowersettings.cpp")
set(groundpathfollowersettingsH "${CMAKE_CURRENT_BINARY_DIR}/groundpathfollowersettings.h")
add_custom_command( 
  OUTPUT  ${groundpathfollowersettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${groundpathfollowersettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(groundtruth "${CMAKE_CURRENT_BINARY_DIR}/groundtruth.cpp")
set(groundtruthH "${CMAKE_CURRENT_BINARY_DIR}/groundtruth.h")
add_custom_command( 
  OUTPUT  ${groundtruth} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${groundtruthH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(gyrosensor "${CMAKE_CURRENT_BINARY_DIR}/gyrosensor.cpp")
set(gyrosensorH "${CMAKE_CURRENT_BINARY_DIR}/gyrosensor.h")
add_custom_command( 
  OUTPUT  ${gyrosensor} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${gyrosensorH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(gyrostate "${CMAKE_CURRENT_BINARY_DIR}/gyrostate.cpp")
set(gyrostateH "${CMAKE_CURRENT_BINARY_DIR}/gyrostate.h")
add_custom_command( 
  OUTPUT  ${gyrostate} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${gyrostateH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(homelocation "${CMAKE_CURRENT_BINARY_DIR}/homelocation.cpp")
set(homelocationH "${CMAKE_CURRENT_BINARY_DIR}/homelocation.h")
add_custom_command( 
  OUTPUT  ${homelocation} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${homelocationH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(hottbridgesettings "${CMAKE_CURRENT_BINARY_DIR}/hottbridgesettings.cpp")
set(hottbridgesettingsH "${CMAKE_CURRENT_BINARY_DIR}/hottbridgesettings.h")
add_custom_command( 
  OUTPUT  ${hottbridgesettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${hottbridgesettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(hottbridgestatus "${CMAKE_CURRENT_BINARY_DIR}/hottbridgestatus.cpp")
set(hottbridgestatusH "${CMAKE_CURRENT_BINARY_DIR}/hottbridgestatus.h")
add_custom_command( 
  OUTPUT  ${hottbridgestatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${hottbridgestatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(hwpikoblxsettings "${CMAKE_CURRENT_BINARY_DIR}/hwpikoblxsettings.cpp")
set(hwpikoblxsettingsH "${CMAKE_CURRENT_BINARY_DIR}/hwpikoblxsettings.h")
add_custom_command( 
  OUTPUT  ${hwpikoblxsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${hwpikoblxsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(hwsettings "${CMAKE_CURRENT_BINARY_DIR}/hwsettings.cpp")
set(hwsettingsH "${CMAKE_CURRENT_BINARY_DIR}/hwsettings.h")
add_custom_command( 
  OUTPUT  ${hwsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${hwsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(hwspracingf3evosettings "${CMAKE_CURRENT_BINARY_DIR}/hwspracingf3evosettings.cpp")
set(hwspracingf3evosettingsH "${CMAKE_CURRENT_BINARY_DIR}/hwspracingf3evosettings.h")
add_custom_command( 
  OUTPUT  ${hwspracingf3evosettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${hwspracingf3evosettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(hwspracingf3settings "${CMAKE_CURRENT_BINARY_DIR}/hwspracingf3settings.cpp")
set(hwspracingf3settingsH "${CMAKE_CURRENT_BINARY_DIR}/hwspracingf3settings.h")
add_custom_command( 
  OUTPUT  ${hwspracingf3settings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${hwspracingf3settingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(hwtinyfishsettings "${CMAKE_CURRENT_BINARY_DIR}/hwtinyfishsettings.cpp")
set(hwtinyfishsettingsH "${CMAKE_CURRENT_BINARY_DIR}/hwtinyfishsettings.h")
add_custom_command( 
  OUTPUT  ${hwtinyfishsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${hwtinyfishsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(i2cstats "${CMAKE_CURRENT_BINARY_DIR}/i2cstats.cpp")
set(i2cstatsH "${CMAKE_CURRENT_BINARY_DIR}/i2cstats.h")
add_custom_command( 
  OUTPUT  ${i2cstats} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${i2cstatsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(magsensor "${CMAKE_CURRENT_BINARY_DIR}/magsensor.cpp")
set(magsensorH "${CMAKE_CURRENT_BINARY_DIR}/magsensor.h")
add_custom_command( 
  OUTPUT  ${magsensor} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${magsensorH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(magstate "${CMAKE_CURRENT_BINARY_DIR}/magstate.cpp")
set(magstateH "${CMAKE_CURRENT_BINARY_DIR}/magstate.h")
add_custom_command( 
  OUTPUT  ${magstate} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${magstateH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(manualcontrolcommand "${CMAKE_CURRENT_BINARY_DIR}/manualcontrolcommand.cpp")
set(manualcontrolcommandH "${CMAKE_CURRENT_BINARY_DIR}/manualcontrolcommand.h")
add_custom_command( 
  OUTPUT  ${manualcontrolcommand} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${manualcontrolcommandH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(manualcontrolsettings "${CMAKE_CURRENT_BINARY_DIR}/manualcontrolsettings.cpp")
set(manualcontrolsettingsH "${CMAKE_CURRENT_BINARY_DIR}/manualcontrolsettings.h")
add_custom_command( 
  OUTPUT  ${manualcontrolsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${manualcontrolsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(mixersettings "${CMAKE_CURRENT_BINARY_DIR}/mixersettings.cpp")
set(mixersettingsH "${CMAKE_CURRENT_BINARY_DIR}/mixersettings.h")
add_custom_command( 
  OUTPUT  ${mixersettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${mixersettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(mixerstatus "${CMAKE_CURRENT_BINARY_DIR}/mixerstatus.cpp")
set(mixerstatusH "${CMAKE_CURRENT_BINARY_DIR}/mixerstatus.h")
add_custom_command( 
  OUTPUT  ${mixerstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${mixerstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(mpugyroaccelsettings "${CMAKE_CURRENT_BINARY_DIR}/mpugyroaccelsettings.cpp")
set(mpugyroaccelsettingsH "${CMAKE_CURRENT_BINARY_DIR}/mpugyroaccelsettings.h")
add_custom_command( 
  OUTPUT  ${mpugyroaccelsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${mpugyroaccelsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(nedaccel "${CMAKE_CURRENT_BINARY_DIR}/nedaccel.cpp")
set(nedaccelH "${CMAKE_CURRENT_BINARY_DIR}/nedaccel.h")
add_custom_command( 
  OUTPUT  ${nedaccel} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${nedaccelH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(objectpersistence "${CMAKE_CURRENT_BINARY_DIR}/objectpersistence.cpp")
set(objectpersistenceH "${CMAKE_CURRENT_BINARY_DIR}/objectpersistence.h")
add_custom_command( 
  OUTPUT  ${objectpersistence} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${objectpersistenceH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(oplinkreceiver "${CMAKE_CURRENT_BINARY_DIR}/oplinkreceiver.cpp")
set(oplinkreceiverH "${CMAKE_CURRENT_BINARY_DIR}/oplinkreceiver.h")
add_custom_command( 
  OUTPUT  ${oplinkreceiver} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${oplinkreceiverH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(oplinksettings "${CMAKE_CURRENT_BINARY_DIR}/oplinksettings.cpp")
set(oplinksettingsH "${CMAKE_CURRENT_BINARY_DIR}/oplinksettings.h")
add_custom_command( 
  OUTPUT  ${oplinksettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${oplinksettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(oplinkstatus "${CMAKE_CURRENT_BINARY_DIR}/oplinkstatus.cpp")
set(oplinkstatusH "${CMAKE_CURRENT_BINARY_DIR}/oplinkstatus.h")
add_custom_command( 
  OUTPUT  ${oplinkstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${oplinkstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(osdsettings "${CMAKE_CURRENT_BINARY_DIR}/osdsettings.cpp")
set(osdsettingsH "${CMAKE_CURRENT_BINARY_DIR}/osdsettings.h")
add_custom_command( 
  OUTPUT  ${osdsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${osdsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(overosyncsettings "${CMAKE_CURRENT_BINARY_DIR}/overosyncsettings.cpp")
set(overosyncsettingsH "${CMAKE_CURRENT_BINARY_DIR}/overosyncsettings.h")
add_custom_command( 
  OUTPUT  ${overosyncsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${overosyncsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(overosyncstats "${CMAKE_CURRENT_BINARY_DIR}/overosyncstats.cpp")
set(overosyncstatsH "${CMAKE_CURRENT_BINARY_DIR}/overosyncstats.h")
add_custom_command( 
  OUTPUT  ${overosyncstats} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${overosyncstatsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(pathaction "${CMAKE_CURRENT_BINARY_DIR}/pathaction.cpp")
set(pathactionH "${CMAKE_CURRENT_BINARY_DIR}/pathaction.h")
add_custom_command( 
  OUTPUT  ${pathaction} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${pathactionH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(pathdesired "${CMAKE_CURRENT_BINARY_DIR}/pathdesired.cpp")
set(pathdesiredH "${CMAKE_CURRENT_BINARY_DIR}/pathdesired.h")
add_custom_command( 
  OUTPUT  ${pathdesired} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${pathdesiredH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(pathplan "${CMAKE_CURRENT_BINARY_DIR}/pathplan.cpp")
set(pathplanH "${CMAKE_CURRENT_BINARY_DIR}/pathplan.h")
add_custom_command( 
  OUTPUT  ${pathplan} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${pathplanH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(pathstatus "${CMAKE_CURRENT_BINARY_DIR}/pathstatus.cpp")
set(pathstatusH "${CMAKE_CURRENT_BINARY_DIR}/pathstatus.h")
add_custom_command( 
  OUTPUT  ${pathstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${pathstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(pathsummary "${CMAKE_CURRENT_BINARY_DIR}/pathsummary.cpp")
set(pathsummaryH "${CMAKE_CURRENT_BINARY_DIR}/pathsummary.h")
add_custom_command( 
  OUTPUT  ${pathsummary} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${pathsummaryH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(perfcounter "${CMAKE_CURRENT_BINARY_DIR}/perfcounter.cpp")
set(perfcounterH "${CMAKE_CURRENT_BINARY_DIR}/perfcounter.h")
add_custom_command( 
  OUTPUT  ${perfcounter} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${perfcounterH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(pidstatus "${CMAKE_CURRENT_BINARY_DIR}/pidstatus.cpp")
set(pidstatusH "${CMAKE_CURRENT_BINARY_DIR}/pidstatus.h")
add_custom_command( 
  OUTPUT  ${pidstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${pidstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(poilearnsettings "${CMAKE_CURRENT_BINARY_DIR}/poilearnsettings.cpp")
set(poilearnsettingsH "${CMAKE_CURRENT_BINARY_DIR}/poilearnsettings.h")
add_custom_command( 
  OUTPUT  ${poilearnsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${poilearnsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(poilocation "${CMAKE_CURRENT_BINARY_DIR}/poilocation.cpp")
set(poilocationH "${CMAKE_CURRENT_BINARY_DIR}/poilocation.h")
add_custom_command( 
  OUTPUT  ${poilocation} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${poilocationH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(positionstate "${CMAKE_CURRENT_BINARY_DIR}/positionstate.cpp")
set(positionstateH "${CMAKE_CURRENT_BINARY_DIR}/positionstate.h")
add_custom_command( 
  OUTPUT  ${positionstate} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${positionstateH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(radiocombridgestats "${CMAKE_CURRENT_BINARY_DIR}/radiocombridgestats.cpp")
set(radiocombridgestatsH "${CMAKE_CURRENT_BINARY_DIR}/radiocombridgestats.h")
add_custom_command( 
  OUTPUT  ${radiocombridgestats} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${radiocombridgestatsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(ratedesired "${CMAKE_CURRENT_BINARY_DIR}/ratedesired.cpp")
set(ratedesiredH "${CMAKE_CURRENT_BINARY_DIR}/ratedesired.h")
add_custom_command( 
  OUTPUT  ${ratedesired} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${ratedesiredH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(receiveractivity "${CMAKE_CURRENT_BINARY_DIR}/receiveractivity.cpp")
set(receiveractivityH "${CMAKE_CURRENT_BINARY_DIR}/receiveractivity.h")
add_custom_command( 
  OUTPUT  ${receiveractivity} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${receiveractivityH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(receiverstatus "${CMAKE_CURRENT_BINARY_DIR}/receiverstatus.cpp")
set(receiverstatusH "${CMAKE_CURRENT_BINARY_DIR}/receiverstatus.h")
add_custom_command( 
  OUTPUT  ${receiverstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${receiverstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(revocalibration "${CMAKE_CURRENT_BINARY_DIR}/revocalibration.cpp")
set(revocalibrationH "${CMAKE_CURRENT_BINARY_DIR}/revocalibration.h")
add_custom_command( 
  OUTPUT  ${revocalibration} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${revocalibrationH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(revosettings "${CMAKE_CURRENT_BINARY_DIR}/revosettings.cpp")
set(revosettingsH "${CMAKE_CURRENT_BINARY_DIR}/revosettings.h")
add_custom_command( 
  OUTPUT  ${revosettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${revosettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(sonaraltitude "${CMAKE_CURRENT_BINARY_DIR}/sonaraltitude.cpp")
set(sonaraltitudeH "${CMAKE_CURRENT_BINARY_DIR}/sonaraltitude.h")
add_custom_command( 
  OUTPUT  ${sonaraltitude} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${sonaraltitudeH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(stabilizationbank "${CMAKE_CURRENT_BINARY_DIR}/stabilizationbank.cpp")
set(stabilizationbankH "${CMAKE_CURRENT_BINARY_DIR}/stabilizationbank.h")
add_custom_command( 
  OUTPUT  ${stabilizationbank} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${stabilizationbankH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(stabilizationdesired "${CMAKE_CURRENT_BINARY_DIR}/stabilizationdesired.cpp")
set(stabilizationdesiredH "${CMAKE_CURRENT_BINARY_DIR}/stabilizationdesired.h")
add_custom_command( 
  OUTPUT  ${stabilizationdesired} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${stabilizationdesiredH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(stabilizationsettings "${CMAKE_CURRENT_BINARY_DIR}/stabilizationsettings.cpp")
set(stabilizationsettingsH "${CMAKE_CURRENT_BINARY_DIR}/stabilizationsettings.h")
add_custom_command( 
  OUTPUT  ${stabilizationsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${stabilizationsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(stabilizationsettingsbank1 "${CMAKE_CURRENT_BINARY_DIR}/stabilizationsettingsbank1.cpp")
set(stabilizationsettingsbank1H "${CMAKE_CURRENT_BINARY_DIR}/stabilizationsettingsbank1.h")
add_custom_command( 
  OUTPUT  ${stabilizationsettingsbank1} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${stabilizationsettingsbank1H} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(stabilizationsettingsbank2 "${CMAKE_CURRENT_BINARY_DIR}/stabilizationsettingsbank2.cpp")
set(stabilizationsettingsbank2H "${CMAKE_CURRENT_BINARY_DIR}/stabilizationsettingsbank2.h")
add_custom_command( 
  OUTPUT  ${stabilizationsettingsbank2} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${stabilizationsettingsbank2H} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(stabilizationsettingsbank3 "${CMAKE_CURRENT_BINARY_DIR}/stabilizationsettingsbank3.cpp")
set(stabilizationsettingsbank3H "${CMAKE_CURRENT_BINARY_DIR}/stabilizationsettingsbank3.h")
add_custom_command( 
  OUTPUT  ${stabilizationsettingsbank3} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${stabilizationsettingsbank3H} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(stabilizationstatus "${CMAKE_CURRENT_BINARY_DIR}/stabilizationstatus.cpp")
set(stabilizationstatusH "${CMAKE_CURRENT_BINARY_DIR}/stabilizationstatus.h")
add_custom_command( 
  OUTPUT  ${stabilizationstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${stabilizationstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(statusgrounddrive "${CMAKE_CURRENT_BINARY_DIR}/statusgrounddrive.cpp")
set(statusgrounddriveH "${CMAKE_CURRENT_BINARY_DIR}/statusgrounddrive.h")
add_custom_command( 
  OUTPUT  ${statusgrounddrive} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${statusgrounddriveH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(statusvtolautotakeoff "${CMAKE_CURRENT_BINARY_DIR}/statusvtolautotakeoff.cpp")
set(statusvtolautotakeoffH "${CMAKE_CURRENT_BINARY_DIR}/statusvtolautotakeoff.h")
add_custom_command( 
  OUTPUT  ${statusvtolautotakeoff} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${statusvtolautotakeoffH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(statusvtolland "${CMAKE_CURRENT_BINARY_DIR}/statusvtolland.cpp")
set(statusvtollandH "${CMAKE_CURRENT_BINARY_DIR}/statusvtolland.h")
add_custom_command( 
  OUTPUT  ${statusvtolland} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${statusvtollandH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(systemalarms "${CMAKE_CURRENT_BINARY_DIR}/systemalarms.cpp")
set(systemalarmsH "${CMAKE_CURRENT_BINARY_DIR}/systemalarms.h")
add_custom_command( 
  OUTPUT  ${systemalarms} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${systemalarmsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(systemidentsettings "${CMAKE_CURRENT_BINARY_DIR}/systemidentsettings.cpp")
set(systemidentsettingsH "${CMAKE_CURRENT_BINARY_DIR}/systemidentsettings.h")
add_custom_command( 
  OUTPUT  ${systemidentsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${systemidentsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(systemidentstate "${CMAKE_CURRENT_BINARY_DIR}/systemidentstate.cpp")
set(systemidentstateH "${CMAKE_CURRENT_BINARY_DIR}/systemidentstate.h")
add_custom_command( 
  OUTPUT  ${systemidentstate} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${systemidentstateH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(systemsettings "${CMAKE_CURRENT_BINARY_DIR}/systemsettings.cpp")
set(systemsettingsH "${CMAKE_CURRENT_BINARY_DIR}/systemsettings.h")
add_custom_command( 
  OUTPUT  ${systemsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${systemsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(systemstats "${CMAKE_CURRENT_BINARY_DIR}/systemstats.cpp")
set(systemstatsH "${CMAKE_CURRENT_BINARY_DIR}/systemstats.h")
add_custom_command( 
  OUTPUT  ${systemstats} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${systemstatsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(takeofflocation "${CMAKE_CURRENT_BINARY_DIR}/takeofflocation.cpp")
set(takeofflocationH "${CMAKE_CURRENT_BINARY_DIR}/takeofflocation.h")
add_custom_command( 
  OUTPUT  ${takeofflocation} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${takeofflocationH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(taskinfo "${CMAKE_CURRENT_BINARY_DIR}/taskinfo.cpp")
set(taskinfoH "${CMAKE_CURRENT_BINARY_DIR}/taskinfo.h")
add_custom_command( 
  OUTPUT  ${taskinfo} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${taskinfoH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(txpidsettings "${CMAKE_CURRENT_BINARY_DIR}/txpidsettings.cpp")
set(txpidsettingsH "${CMAKE_CURRENT_BINARY_DIR}/txpidsettings.h")
add_custom_command( 
  OUTPUT  ${txpidsettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${txpidsettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(txpidstatus "${CMAKE_CURRENT_BINARY_DIR}/txpidstatus.cpp")
set(txpidstatusH "${CMAKE_CURRENT_BINARY_DIR}/txpidstatus.h")
add_custom_command( 
  OUTPUT  ${txpidstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${txpidstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(velocitydesired "${CMAKE_CURRENT_BINARY_DIR}/velocitydesired.cpp")
set(velocitydesiredH "${CMAKE_CURRENT_BINARY_DIR}/velocitydesired.h")
add_custom_command( 
  OUTPUT  ${velocitydesired} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${velocitydesiredH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(velocitystate "${CMAKE_CURRENT_BINARY_DIR}/velocitystate.cpp")
set(velocitystateH "${CMAKE_CURRENT_BINARY_DIR}/velocitystate.h")
add_custom_command( 
  OUTPUT  ${velocitystate} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${velocitystateH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(vtolpathfollowersettings "${CMAKE_CURRENT_BINARY_DIR}/vtolpathfollowersettings.cpp")
set(vtolpathfollowersettingsH "${CMAKE_CURRENT_BINARY_DIR}/vtolpathfollowersettings.h")
add_custom_command( 
  OUTPUT  ${vtolpathfollowersettings} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${vtolpathfollowersettingsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(vtolselftuningstats "${CMAKE_CURRENT_BINARY_DIR}/vtolselftuningstats.cpp")
set(vtolselftuningstatsH "${CMAKE_CURRENT_BINARY_DIR}/vtolselftuningstats.h")
add_custom_command( 
  OUTPUT  ${vtolselftuningstats} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${vtolselftuningstatsH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(watchdogstatus "${CMAKE_CURRENT_BINARY_DIR}/watchdogstatus.cpp")
set(watchdogstatusH "${CMAKE_CURRENT_BINARY_DIR}/watchdogstatus.h")
add_custom_command( 
  OUTPUT  ${watchdogstatus} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${watchdogstatusH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(waypoint "${CMAKE_CURRENT_BINARY_DIR}/waypoint.cpp")
set(waypointH "${CMAKE_CURRENT_BINARY_DIR}/waypoint.h")
add_custom_command( 
  OUTPUT  ${waypoint} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${waypointH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
set(waypointactive "${CMAKE_CURRENT_BINARY_DIR}/waypointactive.cpp")
set(waypointactiveH "${CMAKE_CURRENT_BINARY_DIR}/waypointactive.h")
add_custom_command( 
  OUTPUT  ${waypointactive} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_command( 
  OUTPUT  ${waypointactiveH} 
  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})

set(MyProjectLib_hdr uavobject.h uavdataobject.h   uavobjectfield.h uavmetaobject.h uavobjectmanager.h uavobjectsplugin.h ${accelgyrosettingsH} ${accelsensorH} ${accelstateH} ${accessorydesiredH} ${actuatorcommandH} ${actuatordesiredH} ${actuatorsettingsH} ${airspeedsensorH} ${airspeedsettingsH} ${airspeedstateH} ${altitudefiltersettingsH} ${altitudeholdsettingsH} ${altitudeholdstatusH} ${attitudesettingsH} ${attitudesimulatedH} ${attitudestateH} ${auxmagsensorH} ${auxmagsettingsH} ${barosensorH} ${callbackinfoH} ${cameracontrolactivityH} ${cameracontrolsettingsH} ${cameradesiredH} ${camerastabsettingsH} ${debuglogcontrolH} ${debuglogentryH} ${debuglogsettingsH} ${debuglogstatusH} ${ekfconfigurationH} ${ekfstatevarianceH} ${faultsettingsH} ${firmwareiapobjH} ${fixedwingpathfollowersettingsH} ${fixedwingpathfollowerstatusH} ${flightbatterysettingsH} ${flightbatterystateH} ${flightmodesettingsH} ${flightplancontrolH} ${flightplansettingsH} ${flightplanstatusH} ${flightstatusH} ${flighttelemetrystatsH} ${gcsreceiverH} ${gcstelemetrystatsH} ${gpsextendedstatusH} ${gpspositionsensorH} ${gpssatellitesH} ${gpssettingsH} ${gpstimeH} ${gpsvelocitysensorH} ${groundpathfollowersettingsH} ${groundtruthH} ${gyrosensorH} ${gyrostateH} ${homelocationH} ${hottbridgesettingsH} ${hottbridgestatusH} ${hwpikoblxsettingsH} ${hwsettingsH} ${hwspracingf3evosettingsH} ${hwspracingf3settingsH} ${hwtinyfishsettingsH} ${i2cstatsH} ${magsensorH} ${magstateH} ${manualcontrolcommandH} ${manualcontrolsettingsH} ${mixersettingsH} ${mixerstatusH} ${mpugyroaccelsettingsH} ${nedaccelH} ${objectpersistenceH} ${oplinkreceiverH} ${oplinksettingsH} ${oplinkstatusH} ${osdsettingsH} ${overosyncsettingsH} ${overosyncstatsH} ${pathactionH} ${pathdesiredH} ${pathplanH} ${pathstatusH} ${pathsummaryH} ${perfcounterH} ${pidstatusH} ${poilearnsettingsH} ${poilocationH} ${positionstateH} ${radiocombridgestatsH} ${ratedesiredH} ${receiveractivityH} ${receiverstatusH} ${revocalibrationH} ${revosettingsH} ${sonaraltitudeH} ${stabilizationbankH} ${stabilizationdesiredH} ${stabilizationsettingsH} ${stabilizationsettingsbank1H} ${stabilizationsettingsbank2H} ${stabilizationsettingsbank3H} ${stabilizationstatusH} ${statusgrounddriveH} ${statusvtolautotakeoffH} ${statusvtollandH} ${systemalarmsH} ${systemidentsettingsH} ${systemidentstateH} ${systemsettingsH} ${systemstatsH} ${takeofflocationH} ${taskinfoH} ${txpidsettingsH} ${txpidstatusH} ${velocitydesiredH} ${velocitystateH} ${vtolpathfollowersettingsH} ${vtolselftuningstatsH} ${watchdogstatusH} ${waypointH} ${waypointactiveH} )
set(MyProjectLib_cpp uavobject.cpp uavdataobject.cpp   uavobjectfield.cpp uavmetaobject.cpp uavobjectmanager.cpp   uavobjectsplugin.cpp  ${UAVObjectsInit} ${accelgyrosettings} ${accelsensor} ${accelstate} ${accessorydesired} ${actuatorcommand} ${actuatordesired} ${actuatorsettings} ${airspeedsensor} ${airspeedsettings} ${airspeedstate} ${altitudefiltersettings} ${altitudeholdsettings} ${altitudeholdstatus} ${attitudesettings} ${attitudesimulated} ${attitudestate} ${auxmagsensor} ${auxmagsettings} ${barosensor} ${callbackinfo} ${cameracontrolactivity} ${cameracontrolsettings} ${cameradesired} ${camerastabsettings} ${debuglogcontrol} ${debuglogentry} ${debuglogsettings} ${debuglogstatus} ${ekfconfiguration} ${ekfstatevariance} ${faultsettings} ${firmwareiapobj} ${fixedwingpathfollowersettings} ${fixedwingpathfollowerstatus} ${flightbatterysettings} ${flightbatterystate} ${flightmodesettings} ${flightplancontrol} ${flightplansettings} ${flightplanstatus} ${flightstatus} ${flighttelemetrystats} ${gcsreceiver} ${gcstelemetrystats} ${gpsextendedstatus} ${gpspositionsensor} ${gpssatellites} ${gpssettings} ${gpstime} ${gpsvelocitysensor} ${groundpathfollowersettings} ${groundtruth} ${gyrosensor} ${gyrostate} ${homelocation} ${hottbridgesettings} ${hottbridgestatus} ${hwpikoblxsettings} ${hwsettings} ${hwspracingf3evosettings} ${hwspracingf3settings} ${hwtinyfishsettings} ${i2cstats} ${magsensor} ${magstate} ${manualcontrolcommand} ${manualcontrolsettings} ${mixersettings} ${mixerstatus} ${mpugyroaccelsettings} ${nedaccel} ${objectpersistence} ${oplinkreceiver} ${oplinksettings} ${oplinkstatus} ${osdsettings} ${overosyncsettings} ${overosyncstats} ${pathaction} ${pathdesired} ${pathplan} ${pathstatus} ${pathsummary} ${perfcounter} ${pidstatus} ${poilearnsettings} ${poilocation} ${positionstate} ${radiocombridgestats} ${ratedesired} ${receiveractivity} ${receiverstatus} ${revocalibration} ${revosettings} ${sonaraltitude} ${stabilizationbank} ${stabilizationdesired} ${stabilizationsettings} ${stabilizationsettingsbank1} ${stabilizationsettingsbank2} ${stabilizationsettingsbank3} ${stabilizationstatus} ${statusgrounddrive} ${statusvtolautotakeoff} ${statusvtolland} ${systemalarms} ${systemidentsettings} ${systemidentstate} ${systemsettings} ${systemstats} ${takeofflocation} ${taskinfo} ${txpidsettings} ${txpidstatus} ${velocitydesired} ${velocitystate} ${vtolpathfollowersettings} ${vtolselftuningstats} ${watchdogstatus} ${waypoint} ${waypointactive} )
qt5_wrap_cpp(MyProjectLib_hdr_moc ${MyProjectLib_hdr})
add_definitions(-DUAVOBJECTS_LIBRARY)
add_library(uavobjects SHARED ${MyProjectLib_cpp} ${MyProjectLib_hdr_moc})
include_directories(${PROJECT_SOURCE_DIR})
link_directories (${PROJECT_BINARY_DIR}/utils)
target_link_libraries(uavobjects utils)
testpilot_library(uavobjects)
qt5_use_modules(uavobjects Core Qml)
