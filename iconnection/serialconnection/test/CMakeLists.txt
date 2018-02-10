find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(Qt5Widgets)

add_definitions(-DDEFAULT_CONFIG_FILENAME="default.xml")
add_definitions(-DAPP_NAME="testserial" -DORG_NAME="tcko"
  -DORG_DOMAIN="tcko.com")
add_executable(test_serial testserial.cpp)

include_directories(${PROJECT_SOURCE_DIR})
#link_directories(${PROJECT_BINARY_DIR}/uavobjects)
target_link_libraries (test_serial utils serial)
qt5_use_modules(test_serial Core Widgets)
#set_target_properties( testserial
#    PROPERTIES
#    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
#    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
#    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test"
#)

