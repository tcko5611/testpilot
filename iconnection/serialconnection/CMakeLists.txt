find_package(Qt5 COMPONENTS Core Widgets SerialPort REQUIRED)
#find_package(Qt5Widgets)

add_definitions(-DSERIAL_LIBRARY)
add_library(serial SHARED serialconfig.cpp serialoptionspage.cpp
  serialoptionspage.ui serialplugin.cpp)
add_subdirectory(test)
include_directories(${PROJECT_SOURCE_DIR})
#link_directories(${PROJECT_BINARY_DIR}/uavobjects)
target_link_libraries (serial utils)
qt5_use_modules(serial Core Widgets SerialPort)
