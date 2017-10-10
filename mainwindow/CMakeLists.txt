find_package(Qt5Widgets)
find_package(Qt5Core)
add_library (mainwindow SHARED mainwindow.cpp mainwindow.qrc)
testpilot_library(mainwindow)

include_directories(${PROJECT_SOURCE_DIR}/connectionmanager
  ${PROJECT_SOURCE_DIR}/welcomemode
  ${PROJECT_SOURCE_DIR}/osgearth
  ${PROJECT_SOURCE_DIR}/quickwidgetproxy
  ${PROJECT_SOURCE_DIR}/svgimageprovider
  ${PROJECT_SOURCE_DIR}/modelqmlcontext
  ${PROJECT_SOURCE_DIR}/uavobjects
  )
link_directories (${PROJECT_BINARY_DIR}/connectionmanager
  ${PROJECT_BINARY_DIR}/welcomemode
  ${PROJECT_BINARY_DIR}/osgearth
  ${PROJECT_BINARY_DIR}/quickwidgetproxy
  ${PROJECT_BINARY_DIR}/svgimageprovider
  ${PROJECT_BINARY_DIR}/modelqmlcontext
  ${PROJECT_BINARY_DIR}/uavobjects
  )

target_link_libraries(mainwindow connectionmanager welcomemode
  GCSOsgEarth quickwidgetproxy svgimageprovider modelqmlcontext uavobjects)

qt5_use_modules(mainwindow Widgets Core)
