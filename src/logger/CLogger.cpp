#include "CLogger.h"
#include "Logger.h"

extern "C" {

void LoggerAddLog(const char *From, const char *Message) {
	AppLogger.AddLog(From, Message);
}

void LoggerAddWarning(const char *From, const char *Message) {
	AppLogger.AddWarning(From, Message);
}

void LoggerAddError(const char *From, const char *Message) {
	AppLogger.AddError(From, Message);
}

void LoggerAddSplashLog(const char *From, const char *Message) {
	AppLogger.AddSplashLog(From, Message);
}

void LoggerDestroy() {
	AppLogger.~Logger();
}

}
