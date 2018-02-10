find_package(Qt5Core)
find_package(Qt5Widgets)

add_definitions(-DCORES_LIBRARY)
add_library(cores SHARED connectionmanager.cpp iconnection.cpp 
	generalsettings.cpp generalsettings.ui ioptionspage.cpp)

#testpilot_library(cores)

include_directories(..)
# link_directories(${PROJECT_BINARY_DIR}/uavobjects)
target_link_libraries (cores extensionsystem utils mainwindow)

qt5_use_modules(cores Core Widgets)
