#-------------------------------------------------
#
# Project created by QtCreator 2018-11-11T21:57:17
#
#-------------------------------------------------

#=================================================
# Qt settings.
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#=================================================
# Project settings.
TARGET = zilcheditor
TEMPLATE = app
#=================================================
# Project marco definition.
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#-------------------------------------------------
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#-------------------------------------------------
# Disable MSVC++ compiler security warnings
#DEFINES += _CRT_SECURE_NO_DEPRECATE
DEFINES += _CRT_SECURE_NO_WARNINGS
#-------------------------------------------------
# Compiling environment(cpu).
#DEFINES += PLATFORM_X86
DEFINES += PLATFORM_X86_64
#DEFINES += PLATFORM_ARM64 #(NOT ALLOWED)
# Compiling environment(system).
#DEFINES += PLATFORM_LINUX #(NOT ALLOWED)
DEFINES += PLATFORM_WINDOWS
# JavaScript engine.
DEFINES += JAVASCRIPT_GOOGLE # use Google V8 (NOT ALLOWED)
#DEFINES += JAVASCRIPT_MOZILLA #use Mozilla Spider Monkey (NOT ALLOWED)
#-------------------------------------------------
DEFINES += _HAS_CXX17 # enable ISO/IEC 14882:2017 [MSVC++]
#=================================================
# C++ Standard
#CONFIG += C++11 # use ISO/IEC 14882:2011
#CONFIG += C++14 # use ISO/IEC 14882:2014
CONFIG += C++17 # use ISO/IEC 14882:2017
#CONFIG += C++2a # use C++2a
#=================================================
# Compiler settings
QMAKE_CXXFLAGS += /WX # make warnings as error [MSVC++]
#QMAKE_CXXFLAGS += -Werror # make warnings as error [G++]
QMAKE_CXXFLAGS += /std:c++17 # enable ISO/IEC 14882:2017 [MSVC++]
#QMAKE_CXXFLAGS += -std=c++17 # enable ISO/IEC 14882:2017 [G++]
QMAKE_CFLAGS += /WX # make warnings as error [MSVC]
#QMAKE_CFLAGS += -Werror # make warnings as error [GCC]
#=================================================
# The program version
# {Marjor}.{Minor}.{Revision}.{Build}
VERSION = 0.2.2.626
#=================================================
# Linked libs.
LIBS += -ldbghelp # DbgHelp.dll [Windows]
#=================================================
# Project files.
SOURCES += \
    src/Main.cpp \
    src/stylesheet/StyleSheet.cpp \
    src/logger/Logger.cpp \
    src/widget/MainWindow.cpp \
    src/widget/Widget.cpp \
    src/widget/StageArea.cpp \
    src/widget/StageView.cpp \
    src/translator/Translator.cpp \
    src/scratch/Scratch.cpp \
    src/widget/SpriteArea.cpp \
    src/widget/EditArea.cpp \
    src/widget/ScriptPart.cpp \
    src/widget/BlockItem.cpp \
    src/scratch/ScratchBlockCategory.cpp \
    src/widget/BlockTabItem.cpp \
    src/util/Util.cpp \
    src/logger/CLogger.cpp \
    src/logger/Logger.cpp \
    src/scratch/Scratch.cpp \
    src/scratch/ScratchBlockCategory.cpp \
    src/scratch/ScratchSprite.cpp \
    src/scratch/ScratchStage.cpp \
    src/stylesheet/stylesheet.cpp \
    src/translator/Translator.cpp \
    src/util/Util.cpp \
    src/widget/BlockItem.cpp \
    src/widget/BlockTabItem.cpp \
    src/widget/EditArea.cpp \
    src/widget/MainWindow.cpp \
    src/widget/ScriptPart.cpp \
    src/widget/SpriteArea.cpp \
    src/widget/StageArea.cpp \
    src/widget/StageView.cpp \
    src/widget/Widget.cpp \
    src/Main.cpp \
    src/util/Crash.c \
    src/widget/SpriteItem.cpp \
    src/widget/SpriteListItem.cpp \
    src/scratch/ScratchCostume.cpp \
    src/scratch/ScratchBlockPrototype.cpp \
    src/scratch/ScratchBlock.cpp \
    src/scratch/ScratchObject.cpp \
    src/scratch/ScratchResource.cpp \
    src/util/Resource.cpp \
    src/plugin/PluginPrototype.cpp \
    src/plugin/PluginBase.cpp \
    src/util/Thread.cpp \
    src/widget/StageListItem.cpp \
    src/widget/ObjectListItem.cpp \
    src/widget/costumepart/CostumeListItem.cpp \
    src/widget/costumepart/CostumePart.cpp \
    src/widget/costumepart/CostumeList.cpp \
    src/widget/costumepart/CostumeView.cpp \
    src/widget/costumepart/CostumeNew.cpp \
    src/widget/About.cpp \
    src/widget/LanguageAction.cpp
#-------------------------------------------------
HEADERS += \
    src/stylesheet/StyleSheet.h \
    src/Define.h \
    src/logger/Logger.h \
    src/widget/MainWindow.h \
    src/widget/Widget.h \
    src/widget/StageArea.h \
    src/widget/StageView.h \
    src/translator/Translator.h \
    src/scratch/Scratch.h \
    src/widget/SpriteArea.h \
    src/widget/EditArea.h \
    src/widget/ScriptPart.h \
    src/widget/BlockItem.h \
    src/scratch/ScratchBlockCategory.h \
    src/widget/BlockTabItem.h \
    src/util/Util.h \
    src/logger/CLogger.h \
    src/logger/Logger.h \
    src/scratch/Scratch.h \
    src/scratch/ScratchBlockCategory.h \
    src/scratch/ScratchSprite.h \
    src/scratch/ScratchStage.h \
    src/stylesheet/stylesheet.h \
    src/translator/Translator.h \
    src/util/Crash.h \
    src/util/Util.h \
    src/widget/BlockItem.h \
    src/widget/BlockTabItem.h \
    src/widget/EditArea.h \
    src/widget/MainWindow.h \
    src/widget/ScriptPart.h \
    src/widget/SpriteArea.h \
    src/widget/StageArea.h \
    src/widget/StageView.h \
    src/widget/Widget.h \
    src/Define.h \
    src/widget/SpriteItem.h \
    src/widget/SpriteListItem.h \
    src/scratch/ScratchCostume.h \
    src/scratch/ScratchBlockPrototype.h \
    src/scratch/ScratchBlock.h \
    src/scratch/ScratchObject.h \
    src/scratch/ScratchResource.h \
    src/util/Resource.h \
    src/plugin/PluginPrototype.h \
    src/plugin/PluginBase.h \
    src/util/Thread.h \
    src/widget/StageListItem.h \
    src/widget/ObjectListItem.h \
    src/widget/costumepart/CostumeListItem.h \
    src/widget/costumepart/CostumePart.h \
    src/widget/costumepart/CostumeList.h \
    src/widget/costumepart/CostumeView.h \
    src/widget/costumepart/CostumeNew.h \
    src/widget/About.h \
    src/widget/LanguageAction.h
#-------------------------------------------------
RESOURCES +=
#-------------------------------------------------
DISTFILES += \
    bin/locale/en.yml \
    bin/style/Default.qss
#=================================================
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


