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

add_definitions("-DPLATFORM_WINDOWS -DPLATFORM_X86_64 -D_CRT_SECURE_NO_WARNINGS")

# Set source files
set(project_source_list
src/Main.cpp
src/logger/CLogger.cpp
src/logger/Logger.cpp
src/plugin/PluginBase.cpp
src/plugin/PluginPrototype.cpp
src/scratch/Scratch.cpp
src/scratch/ScratchBlock.cpp
src/scratch/ScratchBlockCategory.cpp
src/scratch/ScratchBlockPrototype.cpp
src/scratch/ScratchCostume.cpp
src/scratch/ScratchObject.cpp
src/scratch/ScratchResource.cpp
src/scratch/ScratchSprite.cpp
src/scratch/ScratchStage.cpp
src/stylesheet/StyleSheet.cpp
src/translator/Translator.cpp
src/util/Crash.c
src/util/Resource.cpp
src/util/Thread.cpp
src/util/Util.cpp
src/widget/About.cpp
src/widget/BlockItem.cpp
src/widget/BlockTabItem.cpp
src/widget/EditArea.cpp
src/widget/LanguageAction.cpp
src/widget/MainWindow.cpp
src/widget/ObjectListItem.cpp
src/widget/ScriptPart.cpp
src/widget/SpriteArea.cpp
src/widget/SpriteItem.cpp
src/widget/SpriteListItem.cpp
src/widget/StageArea.cpp
src/widget/StageView.cpp
src/widget/StageListItem.cpp
src/widget/Widget.cpp
src/widget/costumepart/CostumeList.cpp
src/widget/costumepart/CostumeListItem.cpp
src/widget/costumepart/CostumeNew.cpp
src/widget/costumepart/CostumePart.cpp
src/widget/costumepart/CostumeView.cpp
)

# Tell CMake to create the helloworld executable
add_executable(zilcheditor WIN32 ${project_source_list})

# Use the Widgets module from Qt 5
target_link_libraries(zilcheditor Qt5::Widgets DbgHelp)
