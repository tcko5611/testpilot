#!/mingw64/bin/python

import os
from os.path import basename
import fnmatch
print "find_package(Qt5Core)"
print "find_package(Qt5Qml)"
print "set(CMAKE_AUTOMOC OFF)"
print "set(UAVObjectsInit \"${CMAKE_CURRENT_BINARY_DIR}/uavobjectsinit.cpp\")"

MyProjectLib_hdr ="set(MyProjectLib_hdr uavobject.h uavdataobject.h \
  uavobjectfield.h uavmetaobject.h uavobjectmanager.h "
MyProjectLib_cpp = "set(MyProjectLib_cpp uavobject.cpp uavdataobject.cpp \
  uavobjectfield.cpp uavmetaobject.cpp uavobjectmanager.cpp \
  ${UAVObjectsInit} "
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
                print "add_custom_command( \n\
        OUTPUT ${" + name + "} \n\
        COMMAND ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR} " + name + "\n\
	      WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}\" \n\
        )"
                print "add_custom_command( \n\
        OUTPUT ${" + name + "H} \n\
        COMMAND ${CMAKE_BINARY_DIR}/bin/uavobjgenerator -gcs ${CMAKE_SOURCE_DIR}/xml/uavobjectdefinition ${CMAKE_CURRENT_SOURCE_DIR} " + name + "\n\
	      WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}\" \n\
        )"
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
