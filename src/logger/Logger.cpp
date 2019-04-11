#include "Logger.h"

#include <chrono>
#include <filesystem>
#include <ctime>
#include <cstdio>

LogMsg::LogMsg(std::string from, std::string msg) {
	this->from = from;
	this->msg = msg;
}

Logger::Logger() {
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t ti = std::chrono::system_clock::to_time_t(now);
	char log_file_name[64], log_file_head[64];
	std::strftime(log_file_head, 64, "./log/log-%Y%m%d_%H%M%S", localtime(&ti));
	std::snprintf(log_file_name, 64, "%s.%03lld.log", log_file_head, std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count() % 1000);
	file_name = log_file_name;
	std::freopen(log_file_name, "w", stdout);
	std::freopen(log_file_name, "w", stderr);
	file.open(file_name, std::ios::out);

}

Logger::~Logger() {
	file.flush();
	file.close();
	std::filesystem::copy_file(file_name, "./log/log-latest.log", std::filesystem::copy_options::overwrite_existing);
}

void Logger::InitLogger(QSplashScreen *Splash) {
	this->splash_screen = Splash;
}

std::string Logger::GetFileName() {
	return file_name;
}

