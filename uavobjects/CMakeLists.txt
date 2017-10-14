find_package(Qt5Core)
find_package(Qt5Qml)

add_library (uavobjects SHARED attitudestate1.cpp)
testpilot_library(uavobjects)

qt5_use_modules(uavobjects Core Qml)
