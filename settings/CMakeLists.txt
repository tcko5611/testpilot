find_package(Qt5Widgets)
find_package(Qt5Core)
add_definitions(-DDEFAULT_CONFIG_FILENAME="default.xml")
add_executable(testsettings testsettings.cpp)
add_definitions(-DAPP_NAME="testsetting" -DORG_NAME="tcko" -DORG_DOMAIN="tcko.com")
add_custom_target(
  CopyShare ALL
  COMMAND
  ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/share ${PROJECT_BINARY_DIR}/share
  )

include_directories(${PROJECT_SOURCE_DIR})
target_link_libraries (testsettings utils)
qt5_use_modules(testsettings Widgets Core)

include(CTest)

# does the application run
add_test (NAME TutorialRuns COMMAND testsettings)
set_tests_properties (TutorialRuns PROPERTIES
  PASS_REGULAR_EXPRESSION "9000")
