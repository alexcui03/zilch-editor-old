#include "Crash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../logger/CLogger.h"


#if defined(PLATFORM_WINDOWS)
#include <Windows.h>
#include <DbgHelp.h>
void BindCrashHandler() {
	SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);
}
#elif defined(PLATFORM_LINUX)
void BindCrashHandler() {

}
#elif defined(PLATFORM_OSX)
void BindCrashHandler() {

}
#endif

#if defined(PLATFORM_WINDOWS)
// Windows Only
long ApplicationCrashHandler(void *pException) {
	LoggerAddError("Core", "The program was dumped.");

	// Initialize DbgHelp
	if (SymInitialize(GetCurrentProcess(), NULL, TRUE)) {
		LoggerAddLog("Core", "DbgHelp initialized.");
	}

	// Get system time as the name of dump file.
	SYSTEMTIME SystemTime;
	GetLocalTime(&SystemTime);
	char FileName[50];
	memset(FileName, 0, sizeof(FileName) / sizeof(char));
	sprintf(FileName, "%04d%02d%02d-%02d%02d%02d.%03d.dmp",
		SystemTime.wYear, SystemTime.wMonth, SystemTime.wDay,
		SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond,
		SystemTime.wMilliseconds
	);

	// Create and import dump file.
	HANDLE hDumpFile = CreateFileA(FileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	LoggerAddLog("Core", "Create Dump file successfully.");
	LoggerAddLog("Core", FileName);
	if (hDumpFile != INVALID_HANDLE_VALUE) {
		// Dump info
		MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
		dumpInfo.ExceptionPointers = pException;
		dumpInfo.ThreadId = GetCurrentThreadId();
		dumpInfo.ClientPointers = TRUE;
		// Import dump info to file
		MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &dumpInfo, NULL, NULL);
	}

	DumpCallStack(((EXCEPTION_POINTERS*)pException)->ContextRecord);

	if (SymCleanup(GetCurrentProcess())) {
		LoggerAddLog("Core", "DbgHelp has been cleaned up.");
	}

	return EXCEPTION_EXECUTE_HANDLER;
}

void DumpCallStack(void *pContext) {
	STACKFRAME sf;
	memset(&sf, 0, sizeof(STACKFRAME));

	// Get EIP, ESP, EBP in x86
	// Get RIP, RSP, RBP in x86_64
#if defined(PLATFORM_X86)
	sf.AddrPC.Offset = (CONTEXT*)pContext->Eip;
	sf.AddrPC.Mode = AddrModeFlat;
	sf.AddrStack.Offset = (CONTEXT*)pContext->Esp;
	sf.AddrStack.Mode = AddrModeFlat;
	sf.AddrFrame.Offset = (CONTEXT*)pContext->Ebp;
	sf.AddrFrame.Mode = AddrModeFlat;
#elif defined(PLATFORM_X86_64)
	sf.AddrPC.Offset = ((CONTEXT*)pContext)->Rip;
	sf.AddrPC.Mode = AddrModeFlat;
	sf.AddrStack.Offset = ((CONTEXT*)pContext)->Rsp;
	sf.AddrStack.Mode = AddrModeFlat;
	sf.AddrFrame.Offset = ((CONTEXT*)pContext)->Rbp;
	sf.AddrFrame.Mode = AddrModeFlat;
#endif

	// I386		: x86
	// AMD64	: x86_64
#if defined(PLATFORM_X86)
	DWORD machineType = IMAGE_FILE_MACHINE_I386;
#elif defined(PLATFORM_X86_64)
	DWORD machineType = IMAGE_FILE_MACHINE_AMD64;
#endif

	HANDLE hProcess = GetCurrentProcess();
	HANDLE hThread = GetCurrentThread();

	while (1) {
		if (!StackWalk(machineType, hProcess, hThread, &sf, pContext, 0, SymFunctionTableAccess, SymGetModuleBase, 0)) {
		   break;
		}
		if (sf.AddrFrame.Offset == 0) {
		   break;
		}

		BYTE SymbolBuffer[sizeof(SYMBOL_INFO) + 1024];
		PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)SymbolBuffer;

		pSymbol->SizeOfStruct = sizeof(SymbolBuffer);
		pSymbol->MaxNameLen = 1024;

		char Log[64];
		memset(Log, 0, sizeof(Log) / sizeof(char));

		if (SymFromAddr(hProcess, sf.AddrPC.Offset, 0, pSymbol)) {
			sprintf(Log, "Function: %s", pSymbol->Name);
			LoggerAddLog("DumpInfo", Log);
		}
		else {
			LoggerAddError("DumpInfo", "Function SysFromAddr failed.");
		}

		IMAGEHLP_LINE LineInfo;
		DWORD dwLineDisplacement;
		if (SymGetLineFromAddr(hProcess, sf.AddrPC.Offset, &dwLineDisplacement, &LineInfo)) {
			sprintf(Log, "Source File : %s", LineInfo.FileName);
			LoggerAddLog("DumpInfo", Log);
			sprintf(Log, "Source Line : %lu", LineInfo.LineNumber);
			LoggerAddLog("DumpInfo", Log);
		}
		else {
			LoggerAddError("DumpInfo", "Function SymGetLineFromAddr failed.");
		}
	}
}

#endif
