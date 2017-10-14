find_package(Qt5Xml)

add_executable (uavobjgenerator
  main.cpp
  uavobjectparser.cpp 
  generators/generator_io.cpp 
  generators/java/uavobjectgeneratorjava.cpp 
  generators/flight/uavobjectgeneratorflight.cpp 
  generators/arduino/uavobjectgeneratorarduino.cpp 
  generators/gcs/uavobjectgeneratorgcs.cpp 
  generators/matlab/uavobjectgeneratormatlab.cpp 
  generators/python/uavobjectgeneratorpython.cpp 
  generators/wireshark/uavobjectgeneratorwireshark.cpp
  generators/generator_common.cpp
  )
testpilot_library(uavobjgenerator)
qt5_use_modules(uavobjgenerator Xml)
