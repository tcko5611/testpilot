find_package(Qt5Quick)
find_package(Qt5Svg)

add_library(svgimageprovider SHARED svgimageprovider.cpp)
testpilot_library(svgimageprovider)

qt5_use_modules(svgimageprovider Quick Svg)
