#include <cstdlib>
#include <ctime>

#include <QApplication>
#include <QMenuBar>
#include <QSplashScreen>
#include <QPixmap>
#include <QElapsedTimer>
#include <QMessageBox>
#include <QTime>

#include "widget/MainWindow.h"
#include "logger/Logger.h"
#include "stylesheet/stylesheet.h"
#include "scratch/Scratch.h"
#include "translator/Translator.h"
#include "util/Crash.h"

Logger AppLogger;
Translator AppTranslator;
Scratch ScratchMain;
MainWindow *AppWindow;

int main(int argc, char *argv[]) {
	srand(static_cast<unsigned>(time(nullptr)));
	auto TitleList = GetTitleList();

	QApplication App(argc, argv);

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

	AppWindow = new MainWindow("Zilch Editor: " + TitleList[static_cast<size_t>(rand()) % TitleList.size()]);
	AppWindow->show();
	Splash.finish(AppWindow);

	return App.exec();
}
