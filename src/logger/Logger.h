#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <chrono>
#include <ctime>

#include <QSplashScreen>

class LogMsg {
public:
	LogMsg(std::string from, std::string msg);
public:
	std::string from;
	std::string msg;
};

class Logger {
private:
	std::ofstream file;
	std::string file_name;
	QSplashScreen *splash_screen;
	template<typename ...Ty> void WriteInfo(std::string Type, std::string From, Ty... Message);
public:
	Logger();
	~Logger();
	void InitLogger(QSplashScreen *splash_screen);
	template<typename ...Ty> void AddLog(std::string from, Ty ...msg);
	template<typename ...Ty> void AddWarning(std::string From, Ty ...msg);
	template<typename ...Ty> void AddError(std::string From, Ty ...msg);
	template<typename ...Ty> void AddSplashLog(std::string From, Ty ...msg);
	std::string GetFileName();
};

extern Logger AppLogger;

template<typename ...Ty>
void Logger::WriteInfo(std::string type, std::string from, Ty ...msg) {
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t time = std::chrono::system_clock::to_time_t(now);
	char head[64], phead[64];
	std::strftime(phead, 64, "[%H:%M:%S", localtime(&time));
	std::snprintf(head, 64, "%s.%03lld]", phead, std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count() % 1000);
	file << head << "[" + type + "][" + from + "]";
	(file << ... << msg) << std::endl;
	file.flush();
}

template<typename ...Ty>
void Logger::AddLog(std::string from, Ty ...msg) {
	WriteInfo("Info", from, msg...);
}

template<typename ...Ty>
void Logger::AddWarning(std::string from, Ty ...msg) {
	WriteInfo("Warning", from, msg...);
}

template<typename ...Ty>
void Logger::AddError(std::string from, Ty ...msg) {
	WriteInfo("Error", from, msg...);
}

template<typename ...Ty>
void Logger::AddSplashLog(std::string from, Ty ...msg) {
	WriteInfo("Info", from, msg...);
	std::stringstream stream;
	(stream << ... << msg);
	splash_screen->showMessage(stream.str().c_str(), Qt::AlignLeft | Qt::AlignBottom, Qt::white);
}

#endif // LOGGER_H
