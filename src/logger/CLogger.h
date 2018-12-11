#ifndef CLOGGER_H
#define CLOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

void LoggerAddLog(const char *From, const char *Message);
void LoggerAddWarning(const char *From, const char *Message);
void LoggerAddError(const char *From, const char *Message);
void LoggerAddSplashLog(const char *From, const char *Message);

#ifdef __cplusplus
}
#endif

#endif // CLOGGER_H
