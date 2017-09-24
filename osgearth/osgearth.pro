TEMPLATE = lib
TARGET = GCSOsgEarth
DEFINES += OSGEARTH_LIBRARY

#DEFINES += OSG_VERBOSE

DEFINES += USE_OSG
DEFINES += USE_OSG_QT

DEFINES += USE_OSGEARTH
DEFINES += USE_OSGEARTH_QT

QT += widgets opengl qml quick
contains(DEFINES, OSG_USE_QT_PRIVATE) {
    QT += core-private gui-private
}

# include(../../library.pri)
# include(../utils/utils.pri)

# include(osgearth_dependencies.pri)


# osg and osgearth emit a lot of unused parameter warnings...
QMAKE_CXXFLAGS += -Wno-unused-parameter

HEADERS += \
    osgearth_global.h \
    osgearth.h \
    utils/qtwindowingsystem.h \
    utils/utility.h \
    utils/shapeutils.h

SOURCES += \
    osgearth.cpp \
    utils/qtwindowingsystem.cpp \
    utils/utility.cpp \
    utils/shapeutils.cpp

HEADERS += \
    osgQtQuick/Export.hpp \
    osgQtQuick/DirtySupport.hpp \
    osgQtQuick/OSGNode.hpp \
    osgQtQuick/OSGGroup.hpp \
    osgQtQuick/OSGTransformNode.hpp \
    osgQtQuick/OSGShapeNode.hpp \
    osgQtQuick/OSGImageNode.hpp \
    osgQtQuick/OSGTextNode.hpp \
    osgQtQuick/OSGFileNode.hpp \
    osgQtQuick/OSGBillboardNode.hpp \
    osgQtQuick/OSGCamera.hpp \
    osgQtQuick/OSGViewport.hpp

SOURCES += \
    osgQtQuick/DirtySupport.cpp \
    osgQtQuick/OSGNode.cpp \
    osgQtQuick/OSGGroup.cpp \
    osgQtQuick/OSGTransformNode.cpp \
    osgQtQuick/OSGShapeNode.cpp \
    osgQtQuick/OSGImageNode.cpp \
    osgQtQuick/OSGTextNode.cpp \
    osgQtQuick/OSGFileNode.cpp \
    osgQtQuick/OSGBillboardNode.cpp \
    osgQtQuick/OSGCamera.cpp \
    osgQtQuick/OSGViewport.cpp

HEADERS += \
    osgQtQuick/ga/OSGCameraManipulator.hpp \
    osgQtQuick/ga/OSGNodeTrackerManipulator.hpp \
    osgQtQuick/ga/OSGTrackballManipulator.hpp

SOURCES += \
    osgQtQuick/ga/OSGCameraManipulator.cpp \
    osgQtQuick/ga/OSGNodeTrackerManipulator.cpp \
    osgQtQuick/ga/OSGTrackballManipulator.cpp

HEADERS += \
    osgQtQuick/OSGSkyNode.hpp \
    osgQtQuick/OSGGeoTransformNode.hpp

SOURCES += \
    osgQtQuick/OSGSkyNode.cpp \
    osgQtQuick/OSGGeoTransformNode.cpp

HEADERS += \
    osgQtQuick/ga/OSGEarthManipulator.hpp \
    osgQtQuick/ga/OSGGeoTransformManipulator.hpp

SOURCES += \
    osgQtQuick/ga/OSGEarthManipulator.cpp \
    osgQtQuick/ga/OSGGeoTransformManipulator.cpp

win32:CONFIG(debug, debug|release):DS = "d"

LIBS += -lOpenThreads$${DS} -losg$${DS} -losgUtil$${DS} -losgDB$${DS} -losgGA$${DS} -losgFX$${DS} -losgViewer$${DS} \
        -losgText$${DS} -losgQt$${DS} -losgEarth$${DS} -losgEarthUtil$${DS} -losgEarthFeatures$${DS} \
        -losgEarthSymbology$${DS} -losgEarthAnnotation$${DS} -losgEarthQt$${DS}

copydata.commands = $(COPY_DIR) $$OUT_PWD/debug/GCSOsgEarth.dll $$OUT_PWD/../app/debug
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
