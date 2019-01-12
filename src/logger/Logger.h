#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <QSplashScreen>

class LogMsg {
public:
	LogMsg(std::string From, std::string Message);
public:
	std::string From;
	std::string Message;
};

class Logger {
private:
	std::ofstream File;
	std::string FileName;
	std::list<LogMsg> Error;
	QSplashScreen *Splash;
	void WriteInfo(std::string Type, std::string From, std::string Message);
public:
	Logger();
	~Logger();
	void InitLogger(QSplashScreen *Splash);
	void AddError(std::string From, std::string Message);
	void AddLog(std::string From, std::string Message);
	void AddWarning(std::string From, std::string Message);
	void AddSplashLog(std::string From, std::string Message);
	template<typename ...Ty>
	void AddLog(std::string From, Ty ...Message);
	void AddError(LogMsg Log);
	void AddLog(LogMsg Log);
	void AddWarning(LogMsg Log);
	void AddSplashLog(LogMsg Log);
	std::string GetFileName();
};

extern Logger AppLogger;

template<typename ...Ty>
void Logger::AddLog(std::string From, Ty... Message) {
	std::stringstream Stream;
	(Stream << ... << Message);
	WriteInfo("Info", From, Stream.str());
}

#endif // LOGGER_H
