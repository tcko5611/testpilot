find_package(Qt5Widgets)
find_package(Qt5Opengl)
find_package(Qt5Qml)
find_package(Qt5Quick)

add_definitions(-DOSGEARTH_LIBRARY
  -DUSE_OSG -DUSE_OSG_QT
  -DUSE_OSGEARTH -DUSE_OSGEARTH_QT)

add_library (GCSOsgEarth SHARED
  osgearth.cpp
  utils/qtwindowingsystem.cpp 
  utils/utility.cpp 
  utils/shapeutils.cpp
  osgQtQuick/DirtySupport.cpp 
  osgQtQuick/OSGNode.cpp 
  osgQtQuick/OSGGroup.cpp 
  osgQtQuick/OSGTransformNode.cpp 
  osgQtQuick/OSGShapeNode.cpp 
  osgQtQuick/OSGImageNode.cpp 
  osgQtQuick/OSGTextNode.cpp
  osgQtQuick/OSGFileNode.cpp 
  osgQtQuick/OSGBillboardNode.cpp 
  osgQtQuick/OSGCamera.cpp 
  osgQtQuick/OSGViewport.cpp
  osgQtQuick/ga/OSGCameraManipulator.cpp 
  osgQtQuick/ga/OSGNodeTrackerManipulator.cpp 
  osgQtQuick/ga/OSGTrackballManipulator.cpp
  osgQtQuick/OSGSkyNode.cpp 
  osgQtQuick/OSGGeoTransformNode.cpp
  osgQtQuick/ga/OSGEarthManipulator.cpp 
  osgQtQuick/ga/OSGGeoTransformManipulator.cpp
  )
testpilot_library(GCSOsgEarth)

qt5_use_modules(GCSOsgEarth Widgets Opengl Qml Quick)

target_link_libraries(GCSOsgEarth OpenThreads osg osgUtil osgDB osgGA osgFX
  osgViewer osgText osgQt osgEarth osgEarthUtil osgEarthFeatures
  osgEarthSymbology osgEarthAnnotation osgEarthQt
  )
