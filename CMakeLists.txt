cmake_minimum_required(VERSION 3.14)

project(AutoBatchSamplePlugins LANGUAGES CXX VERSION "1.0.0")

option(SUPPRESS_MULTIPLE_DEFINITIONS
    "Ignore redefinition of options defined in all projects."
    ON
)
if(SUPPRESS_MULTIPLE_DEFINITIONS)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# Set source directory
set(SOURCE_DIRECTORY ${CMAKE_SOURCE_DIR})

# Set debug output
if(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel" )
    add_definitions(-DQT_NO_DEBUG_OUTPUT)
endif()

add_subdirectory(${SOURCE_DIRECTORY}/bufferedcopy)

add_subdirectory(${SOURCE_DIRECTORY}/clitemplate)

add_subdirectory(${SOURCE_DIRECTORY}/download)
add_subdirectory(${SOURCE_DIRECTORY}/filetextreplace)
add_subdirectory(${SOURCE_DIRECTORY}/guitemplate)
add_subdirectory(${SOURCE_DIRECTORY}/helloworld)
add_subdirectory(${SOURCE_DIRECTORY}/makedirectory)

add_subdirectory(${SOURCE_DIRECTORY}/removedirectory)
add_subdirectory(${SOURCE_DIRECTORY}/sleep)

add_subdirectory(${SOURCE_DIRECTORY}/takeline)
add_subdirectory(${SOURCE_DIRECTORY}/testwindow)
