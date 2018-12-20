#-------------------------------------------------
#
# Project created by QtCreator 2018-11-11T21:57:17
#
#-------------------------------------------------

# Qt settings.
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Project settings.
TARGET = ZilchEditor
TEMPLATE = app

# Project marco definition.
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#DEFINES += _CRT_SECURE_NO_DEPRECATE
DEFINES += _CRT_SECURE_NO_WARNINGS
# Compiling environment(cpu).
#DEFINES += PLATFORM_X86 #(NOT ALLOWED)
DEFINES += PLATFORM_X86_64
#DEFINES += PLATFORM_ARM64 #(NOT ALLOWED)
# Compiling environment(system).
#DEFINES += PLATFORM_LINUX #(NOT ALLOWED)
DEFINES += PLATFORM_WINDOWS
# JavaScript engine.
DEFINES += JAVASCRIPT_GOOGLE # use Google V8 (NOT ALLOWED)
#DEFINES += JAVASCRIPT_MOZILLA #use Mozilla Spider Monkey (NOT ALLOWED)

# C++ Standard
#CONFIG += c++11 # use ISO/IEC 14882:2011
#CONFIG += c++14 # use ISO/IEC 14882:2014
CONFIG += c++17 # use ISO/IEC 14882:2017
#CONFIG += c++2a # use C++2a

# Compiler settings
QMAKE_CXXFLAGS += /WX # make warnings as error [MSVC++]
#QMAKE_CXXFLAGS += -Werror # make warnings as error [G++]
#QMAKE_CFLAGS += /WX # make warnings as error [MSVC]
#QMAKE_CFLAGS += -Werror # make warnings as error [GCC]

# The program version
# {Marjor}.{Minor}.{Revision}.{Build}
VERSION = 0.1.0.408

# Linked libs.
LIBS += -ldbghelp # DbgHelp.dll [Windows]

# Project files.
SOURCES += \
    editor/Main.cpp \
    editor/stylesheet/StyleSheet.cpp \
    editor/logger/Logger.cpp \
    editor/widget/MainWindow.cpp \
    editor/widget/Widget.cpp \
    editor/widget/StageArea.cpp \
    editor/widget/StageView.cpp \
    editor/translator/Translator.cpp \
    editor/scratch/Scratch.cpp \
    editor/widget/SpriteArea.cpp \
    editor/widget/EditArea.cpp \
    editor/widget/ScriptPart.cpp \
    editor/widget/CostumePart.cpp \
    editor/widget/BlockItem.cpp \
    editor/scratch/ScratchBlockCategory.cpp \
    editor/widget/BlockTabItem.cpp \
    editor/util/Util.cpp \
    editor/logger/CLogger.cpp \
    editor/logger/Logger.cpp \
    editor/scratch/Scratch.cpp \
    editor/scratch/ScratchBlockCategory.cpp \
    editor/scratch/ScratchSprite.cpp \
    editor/scratch/ScratchStage.cpp \
    editor/stylesheet/stylesheet.cpp \
    editor/translator/Translator.cpp \
    editor/util/Util.cpp \
    editor/widget/BlockItem.cpp \
    editor/widget/BlockTabItem.cpp \
    editor/widget/CostumePart.cpp \
    editor/widget/EditArea.cpp \
    editor/widget/MainWindow.cpp \
    editor/widget/ScriptPart.cpp \
    editor/widget/SpriteArea.cpp \
    editor/widget/StageArea.cpp \
    editor/widget/StageView.cpp \
    editor/widget/Widget.cpp \
    editor/Main.cpp \
    editor/util/Crash.c \
    editor/widget/SpriteItem.cpp \
    editor/widget/SpriteListItem.cpp \
    editor/scratch/ScratchCostume.cpp \
    editor/scratch/ScratchBlockPrototype.cpp \
    editor/scratch/ScratchBlock.cpp \
    editor/scratch/ScratchObject.cpp \
    editor/scratch/ScratchResource.cpp \
    editor/util/Resource.cpp

HEADERS += \
    editor/stylesheet/StyleSheet.h \
    editor/Define.h \
    editor/logger/Logger.h \
    editor/widget/MainWindow.h \
    editor/widget/Widget.h \
    editor/widget/StageArea.h \
    editor/widget/StageView.h \
    editor/translator/Translator.h \
    editor/scratch/Scratch.h \
    editor/widget/SpriteArea.h \
    editor/widget/EditArea.h \
    editor/widget/ScriptPart.h \
    editor/widget/CostumePart.h \
    editor/widget/BlockItem.h \
    editor/scratch/ScratchBlockCategory.h \
    editor/widget/BlockTabItem.h \
    editor/util/Util.h \
    editor/logger/CLogger.h \
    editor/logger/Logger.h \
    editor/scratch/Scratch.h \
    editor/scratch/ScratchBlockCategory.h \
    editor/scratch/ScratchSprite.h \
    editor/scratch/ScratchStage.h \
    editor/stylesheet/stylesheet.h \
    editor/translator/Translator.h \
    editor/util/Crash.h \
    editor/util/Util.h \
    editor/widget/BlockItem.h \
    editor/widget/BlockTabItem.h \
    editor/widget/CostumePart.h \
    editor/widget/EditArea.h \
    editor/widget/MainWindow.h \
    editor/widget/ScriptPart.h \
    editor/widget/SpriteArea.h \
    editor/widget/StageArea.h \
    editor/widget/StageView.h \
    editor/widget/Widget.h \
    editor/Define.h \
    editor/widget/SpriteItem.h \
    editor/widget/SpriteListItem.h \
    editor/scratch/ScratchCostume.h \
    editor/scratch/ScratchBlockPrototype.h \
    editor/scratch/ScratchBlock.h \
    editor/scratch/ScratchObject.h \
    editor/scratch/ScratchResource.h \
    editor/util/Resource.h

RESOURCES +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

