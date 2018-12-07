#include "stylesheet.h"
#include <string>
#include <filesystem>
#include <QFile>
#include <QString>
#include <QApplication>
#include <QDebug>

#include "../logger/Logger.h"

namespace fs = std::experimental::filesystem;

QString LoadStyleSheetString(QSplashScreen *Splash, std::string Path) {
	QString StyleSheetString = "";
	for(auto &c : fs::directory_iterator(Path)) {
		auto FilePath = c.path();
		if (fs::is_directory(FilePath)) {
			StyleSheetString += LoadStyleSheetString(Splash, FilePath.string());
		}
		else {
			AppLogger.AddSplashLog("QSSLoader", "Loading sytlesheet: " + FilePath.filename().string() + "...");
			QFile StyleFile(FilePath.string().c_str());
			StyleFile.open(QFile::ReadOnly);
			StyleSheetString += StyleFile.readAll() + "\n";
			StyleFile.close();
		}
	}
	return StyleSheetString;
}

void LoadStyleSheet(QSplashScreen *Splash, std::string Path) {
	QFile StyleFile("./asset/app.qss");
	StyleFile.open(QFile::ReadOnly);
	QString StyleSheetString = StyleFile.readAll() + "\n";
	StyleFile.close();
	StyleSheetString += LoadStyleSheetString(Splash, Path);

	qApp->setStyleSheet(StyleSheetString);
}

