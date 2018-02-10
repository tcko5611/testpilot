find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Network)
find_package(Qt5Xml)

add_definitions(-DUTILS_LIB)
add_definitions(-DDATA_REL_PATH="../share")
add_definitions(-DLIB_REL_PATH="../lib")
add_definitions(-DPLUGIN_REL_PATH="../lib")
add_library(utils SHARED crc.cpp pathutils.cpp aggregate.cpp threadmanager.cpp
  qtcolorbutton.cpp stylehelper.cpp consoleprocess.cpp abstractprocess_win.cpp
  hostosinfo.cpp consoleprocess_win.cpp winutils.cpp xmlconfig.cpp)

qt5_use_modules(utils Core Widgets Network Xml)
