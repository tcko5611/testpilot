#!/mingw64/bin/python

import os
from os.path import basename
import fnmatch
print "find_package(Qt5Core)"
print "find_package(Qt5Qml)"
print "set(CMAKE_AUTOMOC OFF)"
print "set(UAVObjectsInit \"${CMAKE_CURRENT_BINARY_DIR}/uavobjectsinit.cpp\")"
print "add_custom_command( "
print "  OUTPUT  ${UAVObjectsInit} "
print "  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})"

MyProjectLib_hdr = "set(MyProjectLib_hdr uavobject.h uavdataobject.h \
  uavobjectfield.h uavmetaobject.h uavobjectmanager.h uavobjectsplugin.h "

MyProjectLib_cpp = "set(MyProjectLib_cpp uavobject.cpp uavdataobject.cpp \
  uavobjectfield.cpp uavmetaobject.cpp uavobjectmanager.cpp \
  uavobjectsplugin.cpp  ${UAVObjectsInit} "

for root, dir, files in os.walk("../xml/uavobjectdefinition"):
        print ""
        for items in fnmatch.filter(files, "*.xml"):
                name = os.path.splitext(items)[0]
                print "set(" + name + " \"${CMAKE_CURRENT_BINARY_DIR}/" + \
                        name + ".cpp\")"
                print "set(" + name + "H \"${CMAKE_CURRENT_BINARY_DIR}/" + \
                        name + ".h\")"
                MyProjectLib_cpp += "${" + name + "} "
                MyProjectLib_hdr += "${" + name + "H} "
                print "add_custom_command( "
                print "  OUTPUT  ${" + name +"} "
                print "  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})"
                print "add_custom_command( "
                print "  OUTPUT  ${" + name + "H} "
                print "  COMMAND  ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR})"
        print ""
print MyProjectLib_hdr + ")"
print MyProjectLib_cpp + ")"
print "qt5_wrap_cpp(MyProjectLib_hdr_moc ${MyProjectLib_hdr})"
print "add_definitions(-DUAVOBJECTS_LIBRARY)"
print "add_library(uavobjects SHARED ${MyProjectLib_cpp} ${MyProjectLib_hdr_moc})"



print "include_directories(${PROJECT_SOURCE_DIR})"
print "link_directories (${PROJECT_BINARY_DIR}/utils)"
print "target_link_libraries(uavobjects utils)"
print "testpilot_library(uavobjects)"
print "qt5_use_modules(uavobjects Core Qml)"

print "add_executable(test_uavobjects main.cpp ${MyProjectLib_cpp} ${MyProjectLib_hdr_moc})"
print "target_link_libraries(test_uavobjects utils)"
print "testpilot_library(test_uavobjects)"
print "qt5_use_modules(test_uavobjects Core Qml)"
