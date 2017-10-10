find_package(Qt5Core)
find_package(Qt5Qml)

add_library(modelqmlcontext SHARED modelqmlcontext.cpp)
testpilot_library(modelqmlcontext)
qt5_use_modules(modelqmlcontext Core Qml)
