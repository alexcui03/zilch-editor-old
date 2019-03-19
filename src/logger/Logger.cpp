#include "Logger.h"
#include <ctime>
//#include <filesystem>

LogMsg::LogMsg(std::string From, std::string Message) {
	this->From = From;
	this->Message = Message;
}

Logger::Logger() {

}

Logger::~Logger() {
	File.flush();
	File.close();
	//std::filesystem::copy_file(FileName, "./log/log-latest.log", std::filesystem::copy_options::overwrite_existing);
}

void Logger::InitLogger(QSplashScreen *Splash) {
	this->Splash = Splash;
	time_t Time = time(nullptr);
	char *LogFileName = new char[64]{0};
	strftime(LogFileName, 64, "./log/log-%Y%m%d_%H%M%S.log", localtime(&Time));
	FileName = LogFileName;
	File.open(LogFileName, std::ios::out);
}

std::string Logger::GetFileName() {
	return FileName;
}

