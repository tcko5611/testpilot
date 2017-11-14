#find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Xml)
find_package(Qt5Svg)

add_definitions(-DMAPWIDGET_LIB)
add_library(mapwidget SHARED configuration.cpp gpsitem.cpp homeitem.cpp
  mapgraphicitem.cpp mapresources.qrc mapripform.cpp mapripform.ui
  mapripper.cpp navitem.cpp opmapwidget.cpp trailitem.cpp traillineitem.cpp
  uavitem.cpp waypointcircle.cpp waypointitem.cpp waypointline.cpp
  uavtrailtype.cpp)

testpilot_library(mapwidget)
include_directories(${PROJECT_SOURCE_DIR}/uavobjects
  ${PROJECT_BINARY_DIR}/uavobjects ${PROJECT_SOURCE_DIR}/opmap)
#include_directories(${PROJECT_SOURCE_DIR}/uavobjects
#  ${PROJECT_BINARY_DIR}/uavobjects)
#link_directories(${PROJECT_BINARY_DIR}/uavobjects)
target_link_libraries (mapwidget core internals)
qt5_use_modules(mapwidget Widgets Xml Svg)
