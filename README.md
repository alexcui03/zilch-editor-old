# Zilch Editor

[![](https://img.shields.io/github/license/alexjason/zilch-editor.svg?style=flat-square)](https://www.gnu.org/licenses/gpl-3.0.html)
![](https://img.shields.io/github/languages/code-size/alexjason/zilch-editor.svg?style=flat-square&color=cc9119)
[![](https://img.shields.io/github/release/alexjason/zilch-editor.svg?style=flat-square)](https://github.com/AlexJason/zilch-editor/releases)
![](https://img.shields.io/badge/qt-5.12.1-green.svg?style=flat-square)
![](https://img.shields.io/appveyor/ci/alexjason/zilch-editor.svg?style=flat-square)

Zilch Editor is a powerful scratch editor writed in C++. In plan, Zilch Editor will be an editor that can make any program by installing and using different plugins. The scratch2/scratch3 project can run under original scratch2 plugin or original scratch3 plugin. If you do your project only with anyone of these two plugins, you can export the project as scratch2/scratch3 type. Otherwise, the project in Zilch Editor cannot be opened in scratch2/scratch3.

## Build
To build this project, you need Qt5 library. It's better to use Qt 5.10 or higher to build this project.

You also need a C++ compiler that supports **C++17** and **C11**.

### Build with Qt Creator
At first, you should download the zip file or clone this project by using git.
```bash
git clone https://github.com/AlexJason/zilch-editor.git
```

Open the file {project root}/ZilchEditor.pro

Set defines in project and build it with Qt Creator.

### Build with CMake
At first, you should download the zip file or clone this project by using git.
```bash
git clone https://github.com/AlexJason/zilch-editor.git
cd zilch-editor
git pull origin master
```

Build the project with cmake. If your cmake cannot find Qt library, you need to set environment variable ```CMAKE_PREFIX_PATH``` to your Qt cmake root path. For example ```D:\Program\Qt\5.12.1\msvc2017_64\lib\cmake```.
```bash
mkdir build
cd build
cmake -G "{generator}" .. #use cmake --help to get a complete list of generators
```

On windows, to run this program, you need to copy Qt5Core.dll, Qt5Gui.dll and Qt5Widgets.dll from Qt to the program's working directory.
