#include "app.h"

#include <iostream>
#include <string>

App::App(QObject *parent) : QObject(parent) {
	std::string url, path;
	std::getline(std::cin, url);
	std::getline(std::cin, path);
	downloader = new FileDownloader(url, path);
	connect(this->downloader, SIGNAL(downloaded()), this, SLOT(download()));
}

App::~App() {}

void App::download()  {
	std::cout << downloader->GetData().toStdString() << std::endl;
}
