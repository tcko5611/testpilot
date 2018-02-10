find_package(Qt5QuickWidgets)

add_library(quickwidgetproxy SHARED quickwidgetproxy.cpp)
#testpilot_library(quickwidgetproxy)

qt5_use_modules(quickwidgetproxy QuickWidgets)
