find_package(Qt5Core)

add_library(welcomemode SHARED welcomemode.cpp welcomemode.qrc)
testpilot_library(welcomemode)

include_directories(${PROJECT_SOURCE_DIR}/quickwidgetproxy)
link_directories(${PROJECT_BINARY_DIR}/quickwidgetproxy)
target_link_libraries (welcomemode quickwidgetproxy)
qt5_use_modules(welcomemode Core)
