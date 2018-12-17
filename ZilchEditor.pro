#-------------------------------------------------
#
# Project created by QtCreator 2018-11-11T21:57:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZilchEditor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS _CRT_SECURE_NO_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Compiling environment.
# PLATFORM_X86_64/PLATFORM_X86
#DEFINES += PLATFORM_X86
DEFINES += PLATFORM_X86_64
# PLATFORM_WINDOWS/PLATFORM_LINUX
#DEFINES += PLATFORM_LINUX
DEFINES += PLATFORM_WINDOWS

CONFIG += c++17

# The program version
# {Marjor}.{Minor}.{Revision}.{Build}
VERSION = 0.1.0.301

LIBS += -ldbghelp

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

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ZilchEditor.qrc
