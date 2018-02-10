find_package(Qt5Core)
find_package(Qt5Widgets)

add_definitions(-DEXTENSIONSYSTEM_LIBRARY)
add_definitions(-DGCS_TEST_DIR=\".\")
add_library(extensionsystem SHARED iplugin.cpp optionsparser.cpp
  plugindetailsview.cpp pluginerrorview.cpp pluginmanager.cpp
  pluginspec.cpp pluginview.cpp plugindetailsview.ui pluginview.ui
  pluginerrorview.ui pluginview.qrc)

include_directories(..)
#link_directories(${PROJECT_BINARY_DIR}/uavobjects)
target_link_libraries (extensionsystem utils)
qt5_use_modules(extensionsystem Core Widgets)
