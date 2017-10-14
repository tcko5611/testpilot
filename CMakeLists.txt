cmake_minimum_required(VERSION 3.2)

project(testPilot CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(testPilotFunctions)

add_subdirectory(uavobjgenerator)
add_subdirectory(connectionmanager)
add_subdirectory(modelqmlcontext)
add_subdirectory(quickwidgetproxy)
add_subdirectory(svgimageprovider)
add_subdirectory(testuavobjects)
add_subdirectory(osgearth)
add_subdirectory(welcomemode)
add_subdirectory(mainwindow)
add_subdirectory(app)


