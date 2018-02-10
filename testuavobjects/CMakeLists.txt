find_package(Qt5Core)
find_package(Qt5Qml)

add_library (testuavobjects SHARED attitudestate1.cpp)
#testpilot_library(testuavobjects)

qt5_use_modules(testuavobjects Core Qml)
