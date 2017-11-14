find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Xml)

add_definitions(-DINTERNALS_LIB)
add_library(internals SHARED core.cpp loadtask.cpp MouseWheelZoomType.cpp pointlatlng.cpp pureprojection.cpp rectangle.cpp rectlatlng.cpp sizelatlng.cpp tile.cpp tilematrix.cpp projections/lks94projection.cpp projections/mercatorprojection.cpp projections/mercatorprojectionyandex.cpp projections/platecarreeprojection.cpp projections/platecarreeprojectionpergo.cpp)

# add_library(opmap SHARED flightdatamodel.cpp homeeditor.cpp modelmapproxy.cpp
#   modeluavoproxy.cpp opmap_edit_waypoint_dialog.cpp opmap_statusbar_widget.cpp
#   opmap_zoom_slider_widget.cpp opmapgadget.cpp opmapgadgetconfiguration.cpp
#   opmapgadgetfactory.cpp opmapgadgetoptionspage.cpp opmapgadgetwidget.cpp
#   opmapplugin.cpp pathcompiler.cpp pathplanner.cpp widgetdelegates.cpp
#   homeeditor.ui opmap_edit_waypoint_dialog.ui opmap_overlay_widget.ui
#   opmap_statusbar_widget.ui opmap_widget.ui opmap_widget_complete-post10.ui
#   opmapgadgetoptionspage.ui opmap_zoom_slider_widget.ui pathplanner.ui
#   opmap.qrc)


testpilot_library(internals)
include_directories(${PROJECT_SOURCE_DIR}/uavobjects
  ${PROJECT_BINARY_DIR}/uavobjects ${PROJECT_SOURCE_DIR}/opmap)
#include_directories(${PROJECT_SOURCE_DIR}/uavobjects
#  ${PROJECT_BINARY_DIR}/uavobjects)
#link_directories(${PROJECT_BINARY_DIR}/uavobjects)
target_link_libraries (internals uavobjects core)
qt5_use_modules(internals Core Widgets Xml)
