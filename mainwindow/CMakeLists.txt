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
  ${PROJECT_SOURCE_DIR}/testuavobjects
  ${PROJECT_SOURCE_DIR}/uavobjectwidget
  ${PROJECT_SOURCE_DIR}/uavobjects
  ${PROJECT_SOURCE_DIR}/opmap
  ${PROJECT_BINARY_DIR}/uavobjects
  )

link_directories (${PROJECT_BINARY_DIR}/connectionmanager
  ${PROJECT_BINARY_DIR}/welcomemode
  ${PROJECT_BINARY_DIR}/osgearth
  ${PROJECT_BINARY_DIR}/quickwidgetproxy
  ${PROJECT_BINARY_DIR}/svgimageprovider
  ${PROJECT_BINARY_DIR}/modelqmlcontext
  ${PROJECT_BINARY_DIR}/testuavobjects
  ${PROJECT_BINARY_DIR}/uavobjectwidget
  ${PROJECT_BINARY_DIR}/opmap
  )

#target_link_libraries(mainwindow connectionmanager welcomemode
target_link_libraries(mainwindow uavobjectwidget connectionmanager welcomemode
  GCSOsgEarth quickwidgetproxy svgimageprovider modelqmlcontext testuavobjects
  opmap
  )
#  uavobjectwidget)

qt5_use_modules(mainwindow Widgets Core)
