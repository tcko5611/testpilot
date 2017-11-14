find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Xml)
find_package(Qt5NetWork)
find_package(Qt5Sql)
add_definitions(-DCORE_LIB)

add_library(core SHARED accessmode.cpp alllayersoftype.cpp cache.cpp
  cacheitemqueue.cpp diagnostics.cpp geodecoderstatus.cpp kibertilecache.cpp
  languagetype.cpp maptype.cpp memorycache.cpp opmaps.cpp placemark.cpp
  point.cpp providerstrings.cpp pureimage.cpp pureimagecache.cpp rawtile.cpp
  size.cpp tilecachequeue.cpp urlfactory.cpp)

# add_library(opmap SHARED flightdatamodel.cpp homeeditor.cpp modelmapproxy.cpp
#   modeluavoproxy.cpp opmap_edit_waypoint_dialog.cpp opmap_statusbar_widget.cpp
#   opmap_zoom_slider_widget.cpp opmapgadget.cpp opmapgadgetconfiguration.cpp
#   opmapgadgetfactory.cpp opmapgadgetoptionspage.cpp opmapgadgetwidget.cpp
#   opmapplugin.cpp pathcompiler.cpp pathplanner.cpp widgetdelegates.cpp
#   homeeditor.ui opmap_edit_waypoint_dialog.ui opmap_overlay_widget.ui
#   opmap_statusbar_widget.ui opmap_widget.ui opmap_widget_complete-post10.ui
#   opmapgadgetoptionspage.ui opmap_zoom_slider_widget.ui pathplanner.ui
#   opmap.qrc)


testpilot_library(core)
include_directories(${PROJECT_SOURCE_DIR}/uavobjects
  ${PROJECT_BINARY_DIR}/uavobjects)
include_directories(${PROJECT_SOURCE_DIR}/uavobjects
  ${PROJECT_BINARY_DIR}/uavobjects ${PROJECT_SOURCE_DIR})
#link_directories(${PROJECT_BINARY_DIR}/uavobjects)
target_link_libraries (core utils)
qt5_use_modules(core Core Widgets Xml Network Sql)
