#include <iostream>
#include <string>

#include <QApplication>
#include <QObject>

#include "app.h"
#include "../../src/util/FileDownloader.h"
#include "../../src/logger/Logger.h"

Logger AppLogger;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
	QApplication app(argc, argv);
	App a;
	return app.exec();
}

