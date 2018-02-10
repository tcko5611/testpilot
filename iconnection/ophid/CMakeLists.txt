find_package(Qt5 COMPONENTS Core Widgets SerialPort REQUIRED)
#find_package(Qt5Widgets)

add_definitions(-DOPHID_LIBRARY)
add_library(ophid SHARED src/ophid_plugin.cpp
  src/ophid.cpp src/ophid_usbsignal.cpp src/ophid_hidapi.cpp
  src/ophid_usbmon_win.cpp hidapi/windows/hid.c
  inc/ophid_plugin.h inc/ophid.h inc/ophid_usbmon.h inc/ophid_usbsignal.h
  inc/ophid_hidapi.h)
# add_subdirectory(test)
include_directories(${PROJECT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/inc)
#link_directories(${PROJECT_BINARY_DIR}/uavobjects)
target_link_libraries (ophid utils hid setupapi)
qt5_use_modules(ophid Core Widgets SerialPort)
