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
	QSplashScreen *Splash;
	template<typename ...Ty> void WriteInfo(std::string Type, std::string From, Ty... Message);
public:
	Logger();
	~Logger();
	void InitLogger(QSplashScreen *Splash);
	template<typename ...Ty> void AddLog(std::string From, Ty ...Message);
	template<typename ...Ty> void AddWarning(std::string From, Ty ...Message);
	template<typename ...Ty> void AddError(std::string From, Ty ...Message);
	template<typename ...Ty> void AddSplashLog(std::string From, Ty ...Message);
	std::string GetFileName();
};

extern Logger AppLogger;

template<typename ...Ty>
void Logger::WriteInfo(std::string Type, std::string From, Ty... Message) {
	time_t Time = time(nullptr);
	char *Head = new char[64]{0};
	strftime(Head, 64, "[%H:%M:%S]", localtime(&Time));
	File << Head << "[" + Type + "][" + From + "]";
	(File << ... << Message) << std::endl;
	File.flush();
}

template<typename ...Ty>
void Logger::AddLog(std::string From, Ty... Message) {
	WriteInfo("Info", From, Message...);
}

template<typename ...Ty>
void Logger::AddWarning(std::string From, Ty... Message) {
	WriteInfo("Warning", From, Message...);
}

template<typename ...Ty>
void Logger::AddError(std::string From, Ty... Message) {
	WriteInfo("Error", From, Message...);
}

template<typename ...Ty>
void Logger::AddSplashLog(std::string From, Ty... Message) {
	WriteInfo("Info", From, Message...);
	std::stringstream Stream;
	(Stream << ... << Message);
	Splash->showMessage(Stream.str().c_str(), Qt::AlignLeft | Qt::AlignBottom, Qt::white);
}

#endif // LOGGER_H
