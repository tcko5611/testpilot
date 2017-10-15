# find_package(Qt5Core)
# find_package(Qt5Qml)
# set(AttitudeState "${CMAKE_CURRENT_BINARY_DIR}/attitudestate.cpp")
add_definitions(-DQTCREATOR_UTILS_LIB)
add_library(utils SHARED crc.cpp)
testpilot_library(utils)

#qt5_use_modules(uavobjects Core Qml)
