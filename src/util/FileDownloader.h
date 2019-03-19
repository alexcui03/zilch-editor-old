#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <string>

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class FileDownloader : public QObject {
public:
	FileDownloader(std::string url, QObject *parent = nullptr);
	~FileDownloader();
	bool Finished();
	QByteArray GetData();
private:
	void CreateRequest(std::string url);
signals:
	void downloaded();
private slots:
	void FileDownloaded(QNetworkReply *reply);
private:
	QNetworkAccessManager access_manager;
	QByteArray data;
	bool finished;
};

#endif // FILEDOWNLOADER_H
