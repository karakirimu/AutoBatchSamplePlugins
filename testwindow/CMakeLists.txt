cmake_minimum_required(VERSION 3.14)

project(testwindow LANGUAGES CXX VERSION "1.0.0")
add_compile_definitions(CURRENT_VERSION="${PROJECT_VERSION}")

if(NOT SUPPRESS_MULTIPLE_DEFINITIONS)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets REQUIRED)

# Create Version Information
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/productinfo.cmake)
create_product_info(PRODUCT_INFO)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/plugininterface.cmake)
get_plugin_interface(PLUGIN_INTERFACE)

add_executable(testwindow
    ${PLUGIN_INTERFACE}
    dummytable.h
    dummytable.cpp
    receivelistdialog.h
    receivelistdialog.cpp
    receivelistdialog.ui
    testwindow.h
    testwindow.cpp
    main.cpp
    testwindow.ui
    ${PRODUCT_INFO}
)

if(WIN32)
    set_property(TARGET testwindow PROPERTY WIN32_EXECUTABLE true)
endif()

target_link_libraries(testwindow 
  PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)
