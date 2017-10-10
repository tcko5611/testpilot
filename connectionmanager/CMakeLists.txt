find_package(Qt5Widgets)

add_library(connectionmanager SHARED connectionmanager.cpp)

testpilot_library(connectionmanager)

qt5_use_modules(connectionmanager Widgets)

