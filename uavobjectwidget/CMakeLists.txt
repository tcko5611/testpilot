find_package(Qt5Core)
find_package(Qt5Widgets)

add_definitions(-DQTCREATOR_UTILS_LIB)
add_library(uavobjectwidget SHARED browseritemdelegate.cpp
  fieldtreeitem.cpp treeitem.cpp QScienceSpinBox.cpp qtcolorbutton.cpp
  ioptionspage.cpp uavobjectbrowseroptionspage.cpp
  uavobjectbrowserwidget.cpp uavobjecttreemodel.cpp
  uavobjectbrowseroptionspage.ui uavobjectbrowser.ui viewoptions.ui
  uavobjectbrowser.qrc)
# add_executable(uavobjectwidget main.cpp browseritemdelegate.cpp
#   fieldtreeitem.cpp treeitem.cpp QScienceSpinBox.cpp qtcolorbutton.cpp
#   ioptionspage.cpp	uavobjectbrowseroptionspage.cpp
#   uavobjectbrowserwidget.cpp uavobjecttreemodel.cpp
#   uavobjectbrowseroptionspage.ui uavobjectbrowser.ui viewoptions.ui
#   uavobjectbrowser.qrc)

#testpilot_library(uavobjectwidget)

include_directories(${PROJECT_SOURCE_DIR}/uavobjects
  ${PROJECT_BINARY_DIR}/uavobjects)
link_directories(${PROJECT_BINARY_DIR}/uavobjects)
target_link_libraries (uavobjectwidget uavobjects)
qt5_use_modules(uavobjectwidget Core Widgets)
