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
    src/widget/CostumePart.cpp \
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
    src/widget/CostumePart.cpp \
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
    src/util/Resource.cpp

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
    src/widget/CostumePart.h \
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
    src/widget/CostumePart.h \
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
    src/util/Resource.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ZilchEditor.qrc
