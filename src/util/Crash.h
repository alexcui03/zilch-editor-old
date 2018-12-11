#ifndef CRASH_H
#define CRASH_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

void BindCrashHandler(void);

// For Windows
#if defined(PLATFORM_WINDOWS)
long ApplicationCrashHandler(void *pException);
void DumpCallStack(void *pContext);
#elif defined(PLATFORM_LINUX)

#elif defined(PLATFORM_OSX)

#endif

#ifdef __cplusplus
}
#endif

#endif // CRASH_H
