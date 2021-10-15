cmake_minimum_required(VERSION 3.14)

project(takeline LANGUAGES CXX VERSION "1.0.0")

if(NOT SUPPRESS_MULTIPLE_DEFINITIONS)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets LinguistTools REQUIRED)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/productinfo.cmake)
create_product_info(PRODUCT_INFO)


# Create Version Information
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/plugininterface.cmake)
get_plugin_interface(PLUGIN_INTERFACE)

add_library(takeline
  SHARED
    ${PLUGIN_INTERFACE}
    takeline_global.h
    takeline.cpp
    takeline.h
    takelinewidget.cpp
    takelinewidget.h
    takelinewidget.ui
    takeline.json
    ${PRODUCT_INFO}
)

target_link_libraries(takeline
  PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_compile_definitions(takeline PRIVATE TAKELINE_LIBRARY)

# Create Language Files
set(TS_SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/translation)
set(TS_FILES
    takeline_en.ts
    takeline_ja.ts
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_create_translation(QM_FILES ${TS_SOURCE_DIRECTORY} ${TS_FILES})
else()
    qt5_create_translation(QM_FILES ${TS_SOURCE_DIRECTORY} ${TS_FILES})
endif()
