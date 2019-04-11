#include "FileDownloader.h"

#include <QNetworkRequest>
#include <QUrl>

#include "../logger/Logger.h"

FileDownloader::FileDownloader(std::string url, QObject *parent) : QObject(parent) {
	this->CreateRequest(url);
}

FileDownloader::~FileDownloader() {

}

bool FileDownloader::Finished() {
	return this->finished;
}

void FileDownloader::CreateRequest(std::string url) {
	QNetworkRequest request(QUrl(url.c_str()));
	AppLogger.AddLog("Network", "GET ", url);
	this->access_manager.get(request);

	connect(&this->access_manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(FileDownloaded(QNetworkReply *)));
}

void FileDownloader::FileDownloaded(QNetworkReply *reply) {
	AppLogger.AddLog("Network", "RESPONSE ", reply->url().toString().toStdString());
	this->data = reply->readAll();
	reply->deleteLater();
	this->finished = true;
	AppLogger.AddLog("Network", "CLEAN ", reply->url().toString().toStdString());
	emit downloaded();
}

QByteArray FileDownloader::GetData() {
	return this->data;
}
