#include "Updater.h"

#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringList>

#include "../logger/Logger.h"
#include "../util/FileDownloader.h"

std::vector<Updater::UpdateSource> Updater::source_list;
std::string Updater::select_source;

void Updater::loadSourceListFromConfig() {
	// load file config/source.json
	QFile file("./config/source.json");
	if (!file.open(QIODevice::ReadOnly)) {
		AppLogger.AddError("Config", "Cannot load \"config/source.json\"");
		return;
	}

	QByteArray data = file.readAll();
	file.close();

	// load json data
	QJsonDocument json(QJsonDocument::fromJson(data));

	QJsonObject json_root = json.object();

	// load source list
	QJsonObject json_list = json_root.value("list").toObject();
	for (const auto &c : json_list.keys()) {
		UpdateSource us = {c.toStdString(), json_list.value(c).toString().toStdString()};
		source_list.push_back(us);
	}

	select_source = json_root.value("select").toString().toStdString();
}

void Updater::getServerData() {
	std::string url = "http://127.0.0.1:32000/win64.json";
	FileDownloader *downloader = new FileDownloader(url);
	AppLogger.AddLog("Updater", "Get information from ", url);
	while(downloader->Finished());
	AppLogger.AddLog("Updater", "Response from ", url);

	QJsonParseError json_err;
	QJsonDocument json_doc(QJsonDocument::fromJson(downloader->GetData(), &json_err));
	if (json_err.error != QJsonParseError::NoError) {
		AppLogger.AddError("Updater", "Json parse error.");
		return;
	}

	QJsonObject json_root = json_doc.object();
	std::string latest_release = json_root.value("latest-release").toString().toStdString();
	std::string latest_beta = json_root.value("latest-beta").toString().toStdString();
	std::string latest_alpha = json_root.value("latest-alpha").toString().toStdString();
	AppLogger.AddLog("Updater", "Network: RESPONSE FROM ", url);
	AppLogger.AddLog("Updater", "Network: RESPONSE FROM ", url);
}

