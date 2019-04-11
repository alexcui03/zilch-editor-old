cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

project(zilch-editor)

set(PROJECT_SRC_DIRS
    src
    src/logger
    src/plugin
    src/scratch
    src/stylesheet
    src/translator
    src/updater
    src/util
    src/widget
    src/widget/scriptpart
    src/widget/costumepart
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

foreach(DIR ${PROJECT_SRC_DIRS})
    aux_source_directory(${DIR} PROJECT_SRC_FILES)
endforeach()

message(CMAKE_GENERATOR_PLATFORM: ${CMAKE_GENERATOR_PLATFORM})
message(CMAKE_GENERATOR_INSTANCE: ${CMAKE_GENERATOR_INSTANCE})
message(CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME})
message(CMAKE_HOST_SYSTEM_NAME: ${CMAKE_HOST_SYSTEM_NAME})
message(CMAKE_SYSTEM_VERSION: ${CMAKE_SYSTEM_VERSION})

if(MSVC)
    message(MSVC_TOOLSET_VERSION: ${MSVC_TOOLSET_VERSION})
    message(MSVC_VERSION: ${MSVC_VERSION})
    add_compile_options(/W4 /WX /wd4458)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_HAS_CXX17)
    if(MSVC_VERSION GREATER_EQUAL 1920)
        add_definitions(-D_HAS_CXX20)
    endif()
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

if(CMAKE_GENERATOR_PLATFORM MATCHES x64)
    add_definitions(-DPLATFORM_X86_64)
else()
    add_definitions(-DPLATFORM_X86)
endif()

if(WIN32)
    add_definitions(-DPLATFORM_WINDOWS)
else()
    if(APPLE)
        if(IOS)
            add_definitions(-DPLATFORM_IOS)
        else()
            add_definitions(-DPLATFORM_MACOSX)
        endif()
    elseif(ANDROID)
        add_definitions(-DPLATFORM_ANDROID)
    else()
        add_definitions(-DPLATFORM_UNIX)
    endif()
endif()

add_executable(zilcheditor ${PROJECT_SRC_FILES})

if(WIN32)
    target_link_libraries(zilcheditor Qt5::Widgets Qt5::Network DbgHelp)
else()
    target_link_libraries(zilcheditor Qt5::Widgets Qt5::Network)
endif()
