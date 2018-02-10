#find_package(Qt5Core)
#find_package(Qt5Widgets)

add_definitions(-DUAVTALK_LIB)
add_library(uavtalk oplinkmanager.cpp telemetry.cpp telemetrymanager.cpp
  telemetrymonitor.cpp uavtalk.cpp uavtalkplugin.cpp)

#testpilot_library(uavtalk)

include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/uavobjects )
#link_directories(${PROJECT_BINARY_DIR}/uavobjects)
target_link_libraries (uavtalk uavobjects cores)
#qt5_use_modules(uavobjectwidget Core Widgets)
