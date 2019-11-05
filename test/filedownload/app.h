#include <QObject>

#include "../../src/util/FileDownloader.h"
#include "../../src/logger/Logger.h"

class App : public QObject {
	Q_OBJECT
public:
	App(QObject *parent = nullptr);
	~App();
	FileDownloader *downloader;
public slots:
	void download();
};
