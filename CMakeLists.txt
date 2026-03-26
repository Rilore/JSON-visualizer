cmake_minimum_required(VERSION 3.28.3)

project(json-visiualizer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
find_package(GTest REQUIRED)

add_subdirectory(3dparty/json)
add_subdirectory(src/app)

qt_standard_project_setup()

target_link_libraries(json-visiualizer PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    nlohmann_json::nlohmann_json
)

set_target_properties(json-visiualizer PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS json-visiualizer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

add_executable(test_json-visualize test/main_test.cpp)
target_link_libraries(test_json-visualize PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    GTest::gtest
    GTest::gtest_main
    nlohmann_json::nlohmann_json
)
