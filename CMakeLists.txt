# Qt5 requires CMake 3.1.10 or higher.
cmake_minimum_required(VERSION 3.1.10)

project(zilch-editor)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
# Use C11
set(CMAKE_C_STANDARD 11)
# Find includes in corresponding build directories.
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

add_definitions("-DPLATFORM_WINDOWS -DPLATFORM_X86_64 -D_CRT_SECURE_NO_WARNINGS -D_HAS_CXX17 -D_HAS_CXX20 -Wall -Werror")

# Set source files
set(PROJECT_SRC_DIRS
    src/
    src/logger/
    src/plugin/
    src/scratch/
    src/stylesheet/
    src/translator/
    src/updater/
    src/util/
    src/widget/
)

foreach(DIR ${PROJECT_SRC_DIRS})
    aux_source_directory(${DIR} TEMP_VAR)
    set(PROJECT_SRC_FILES ${PROJECT_SRC_FILES} ${TEMP_VAR})
endforeach(DIR)

# Tell CMake to create the helloworld executable
add_executable(zilcheditor ${PROJECT_SRC_FILES})

# Use the Widgets module from Qt 5
target_link_libraries(zilcheditor Qt5::Widgets DbgHelp)
