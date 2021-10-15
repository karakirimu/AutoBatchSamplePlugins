cmake_minimum_required(VERSION 3.14)

project(removedirectory LANGUAGES CXX VERSION "1.0.0")

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

# Create Version Information
include(${CMAKE_CURRENT_LIST_DIR}/../cmake/productinfo.cmake)
create_product_info(PRODUCT_INFO)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/plugininterface.cmake)
get_plugin_interface(PLUGIN_INTERFACE)

add_library(removedirectory
  SHARED
    ${PLUGIN_INTERFACE}
    removedirectory_global.h
    removedirectory.cpp
    removedirectory.h
    removedirectorywidget.cpp
    removedirectorywidget.h
    removedirectorywidget.ui
    removedirectory.json
    ${PRODUCT_INFO}
)

target_link_libraries(removedirectory
  PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_compile_definitions(removedirectory PRIVATE REMOVEDIRECTORY_LIBRARY)

# Create Language Files
set(TS_SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/translation)
set(TS_FILES
    removedirectory_en.ts
    removedirectory_ja.ts
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_create_translation(QM_FILES ${TS_SOURCE_DIRECTORY} ${TS_FILES})
else()
    qt5_create_translation(QM_FILES ${TS_SOURCE_DIRECTORY} ${TS_FILES})
endif()
