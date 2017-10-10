find_package(Qt5Widgets)
include_directories(${PROJECT_SOURCE_DIR}/mainwindow)
link_directories (${PROJECT_BINARY_DIR}/mainwindow)
add_executable (testPilot main.cpp)
testpilot_library(testPilot)

target_link_libraries (testPilot mainwindow)
qt5_use_modules(testPilot Widgets)
file(COPY share DESTINATION ${PROJECT_BINARY_DIR}/bin)
