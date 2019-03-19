#include <cstdlib>
#include <ctime>

#include <QApplication>
#include <QMenuBar>
#include <QSplashScreen>
#include <QPixmap>
#include <QElapsedTimer>
#include <QMessageBox>
#include <QTime>
#include <QStyleFactory>

#include "widget/MainWindow.h"
#include "logger/Logger.h"
#include "stylesheet/stylesheet.h"
#include "scratch/Scratch.h"
#include "translator/Translator.h"
#include "util/Crash.h"

#include <QDebug>

Logger AppLogger;
Translator AppTranslator;
Scratch ScratchMain;
MainWindow *AppWindow;

int main(int argc, char *argv[]) {
	QApplication App(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	BindCrashHandler();

	QSplashScreen Splash(QPixmap("./asset/splash.png"));
	AppLogger.InitLogger(&Splash);
	Splash.setDisabled(true);
	Splash.show();

	AppLogger.AddSplashLog("Core", "Loading stylesheet...");
	LoadStyleSheet(&Splash, "./style/");
	AppLogger.AddSplashLog("Core", "Loading plugin...");
	AppLogger.AddSplashLog("Core", "Loading translation...");
	AppTranslator.LoadTranslation("./locale/");
	AppTranslator.SetLanguage();

	AppWindow = new MainWindow("Zilch Editor");
	AppWindow->show();
	Splash.finish(AppWindow);

	int Result = App.exec();
	AppLogger.AddLog("Core", "Clean up resources");
	AppLogger.AddLog("Core", "Program exited with code ", Result);
	return Result;
}
