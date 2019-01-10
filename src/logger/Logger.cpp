#include "Logger.h"
#include <ctime>
#include <filesystem>

LogMsg::LogMsg(std::string From, std::string Message) {
	this->From = From;
	this->Message = Message;
}

Logger::Logger() {

}

Logger::~Logger() {
	File.flush();
	File.close();
	std::filesystem::copy_file(FileName, "./log/log-latest.log", std::filesystem::copy_options::overwrite_existing);
}

void Logger::InitLogger(QSplashScreen *Splash) {
	this->Splash = Splash;
	time_t Time = time(nullptr);
	char *LogFileName = new char[64]{0};
	strftime(LogFileName, 64, "./log/log-%Y%m%d_%H%M%S.log", localtime(&Time));
	FileName = LogFileName;
	File.open(LogFileName, std::ios::out);
}

void Logger::WriteInfo(std::string Type, std::string From, std::string Message) {
	time_t Time = time(nullptr);
	char *Head = new char[64]{0};
	strftime(Head, 64, "[%H:%M:%S]", localtime(&Time));
	File << Head << "[" + Type + "][" + From + "]" + Message + "\n";
	File.flush();
}

void Logger::AddLog(std::string From, std::string Message) {
	AddLog(LogMsg(From, Message));
}

void Logger::AddError(std::string From, std::string Message) {
	AddError(LogMsg(From, Message));
}

void Logger::AddWarning(std::string From, std::string Message) {
	AddWarning(LogMsg(From, Message));
}

void Logger::AddSplashLog(std::string From, std::string Message) {
	AddSplashLog(LogMsg(From, Message));
}

void Logger::AddError(LogMsg Log) {
	WriteInfo("Error", Log.From, Log.Message);
	Error.push_back(Log);
}

void Logger::AddLog(LogMsg Log) {
	WriteInfo("Log", Log.From, Log.Message);
}

void Logger::AddWarning(LogMsg Log) {
	WriteInfo("Warning", Log.From, Log.Message);
}

void Logger::AddSplashLog(LogMsg Log) {
	AddLog(Log);
	Splash->showMessage(Log.Message.c_str(), Qt::AlignLeft | Qt::AlignBottom, Qt::white);
}

std::string Logger::GetFileName() {
	return FileName;
}

