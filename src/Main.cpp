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
	QApplication app(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	BindCrashHandler();

	QSplashScreen splash(QPixmap("./asset/splash.png"));
	AppLogger.InitLogger(&splash);
	splash.setDisabled(true);
	splash.show();

	AppLogger.AddSplashLog("Core", "Loading stylesheet...");
	LoadStyleSheet(&splash, "./style/");
	AppLogger.AddSplashLog("Core", "Loading plugin...");
	AppLogger.AddSplashLog("Core", "Loading translation...");
	AppTranslator.LoadTranslation("./locale/");
	AppTranslator.SetLanguage();

	AppWindow = new MainWindow("Zilch Editor - Alpha Version");
	AppWindow->show();
	splash.finish(AppWindow);

	int result = app.exec();
	AppLogger.AddLog("Core", "Clean up resources");
	AppLogger.AddLog("Core", "Program exited with code ", result);
	return result;
}
