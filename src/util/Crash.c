#include "Crash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../logger/CLogger.h"

void ConvertNumberBin64(char *Buffer, uint64_t Value) {
	for (int i = 63; i >= 0; i--) {
		Buffer[i] = (Value & 0x01) + 48;
		Value >>= 1;
	}
}

void ConvertNumberBin32(char *Buffer, uint32_t Value) {
	for (int i = 31; i >= 0; i--) {
		Buffer[i] = (Value & 0x01) + 48;
		Value >>= 1;
	}
}

void ConvertNumberBin16(char *Buffer, uint16_t Value) {
	for (int i = 15; i >= 0; i--) {
		Buffer[i] = (Value & 0x01) + 48;
		Value >>= 1;
	}
}

void ConvertNumberBin8(char *Buffer, uint8_t Value) {
	for (int i = 7; i >= 0; i--) {
		Buffer[i] = (Value & 0x01) + 48;
		Value >>= 1;
	}
}

void OutputCPUStatus64(char *Buffer, const char *Name, uint64_t Value) {
	static char Temp[65] = { 0 };
	ConvertNumberBin64(Temp, Value);
	sprintf(Buffer, "%-8s: 0x%016llX %2s %64s", Name, Value, "", Temp);
	LoggerAddLog("DumpInfo", Buffer);
}

void OutputCPUStatus32(char *Buffer, const char *Name, uint32_t Value) {
	static char Temp[33] = { 0 };
	ConvertNumberBin32(Temp, Value);
	sprintf(Buffer, "%-8s: 0x%08X %10s %64s", Name, Value, "", Temp);
	LoggerAddLog("DumpInfo", Buffer);
}

void OutputCPUStatus16(char *Buffer, const char *Name, uint16_t Value) {
	static char Temp[17] = { 0 };
	ConvertNumberBin32(Temp, Value);
	sprintf(Buffer, "%-8s: 0x%04hX %14s %64s", Name, Value, "", Temp);
	LoggerAddLog("DumpInfo", Buffer);
}

#if defined(PLATFORM_WINDOWS)
#include <Windows.h>
#include <DbgHelp.h>
LONG ApplicationCrashHandler(EXCEPTION_POINTERS *pException);
void DumpCallStack(CONTEXT *pContext);
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
long ApplicationCrashHandler(EXCEPTION_POINTERS *pException) {
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

	DumpCallStack(pException->ContextRecord);

	if (SymCleanup(GetCurrentProcess())) {
		LoggerAddLog("Core", "DbgHelp has been cleaned up.");
	}

	return EXCEPTION_EXECUTE_HANDLER;
}

void DumpCallStack(CONTEXT *pContext) {
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
	sf.AddrPC.Offset = pContext->Rip;
	sf.AddrPC.Mode = AddrModeFlat;
	sf.AddrStack.Offset = pContext->Rsp;
	sf.AddrStack.Mode = AddrModeFlat;
	sf.AddrFrame.Offset = pContext->Rbp;
	sf.AddrFrame.Mode = AddrModeFlat;
#endif

	// I386		: x86
	// AMD64	: x86_64
#if defined(PLATFORM_X86)
	DWORD MachineType = IMAGE_FILE_MACHINE_I386;
#elif defined(PLATFORM_X86_64)
	DWORD MachineType = IMAGE_FILE_MACHINE_AMD64;
#endif

#if defined(PLATFORM_X86)
#elif defined(PLATFORM_X86_64)
	LoggerAddLog("DumpInfo", "CPU status:");
	LoggerAddLog("DumpInfo", "CPU type: AMD64(x86_64)");
	char Log[128];
	memset(Log, 0, sizeof(Log) / sizeof(char));
	LoggerAddLog("DumpInfo", "Integer registers:");
	OutputCPUStatus64(Log, "RAX",	pContext->Rax);
	OutputCPUStatus64(Log, "RBX",	pContext->Rbx);
	OutputCPUStatus64(Log, "RCX",	pContext->Rcx);
	OutputCPUStatus64(Log, "RDX",	pContext->Rdx);
	OutputCPUStatus64(Log, "RSP",	pContext->Rsp);
	OutputCPUStatus64(Log, "RBP",	pContext->Rbp);
	OutputCPUStatus64(Log, "RSI",	pContext->Rsi);
	OutputCPUStatus64(Log, "RDI",	pContext->Rdi);
	OutputCPUStatus64(Log, "R8",	pContext->R8);
	OutputCPUStatus64(Log, "R9",	pContext->R9);
	OutputCPUStatus64(Log, "R10",	pContext->R10);
	OutputCPUStatus64(Log, "R11",	pContext->R11);
	OutputCPUStatus64(Log, "R12",	pContext->R12);
	OutputCPUStatus64(Log, "R13",	pContext->R13);
	OutputCPUStatus64(Log, "R14",	pContext->R14);
	OutputCPUStatus64(Log, "R15",	pContext->R15);
	LoggerAddLog("DumpInfo", "Program counter:");
	OutputCPUStatus64(Log, "RIP",	pContext->Rip);
	LoggerAddLog("DumpInfo", "Debug registers:");
	OutputCPUStatus64(Log, "DR0",	pContext->Dr0);
	OutputCPUStatus64(Log, "DR1",	pContext->Dr1);
	OutputCPUStatus64(Log, "DR2",	pContext->Dr2);
	OutputCPUStatus64(Log, "DR3",	pContext->Dr3);
	OutputCPUStatus64(Log, "DR6",	pContext->Dr6);
	OutputCPUStatus64(Log, "DR7",	pContext->Dr7);
	LoggerAddLog("DumpInfo", "Segment Registers and processor flags:");
	OutputCPUStatus16(Log, "CS",	pContext->SegCs);
	OutputCPUStatus16(Log, "DS",	pContext->SegDs);
	OutputCPUStatus16(Log, "ES",	pContext->SegEs);
	OutputCPUStatus16(Log, "FS",	pContext->SegFs);
	OutputCPUStatus16(Log, "GS",	pContext->SegGs);
	OutputCPUStatus16(Log, "SS",	pContext->SegSs);
	OutputCPUStatus32(Log, "EFLAGS",pContext->EFlags);
#endif

	HANDLE hProcess = GetCurrentProcess();
	HANDLE hThread = GetCurrentThread();

	while (1) {
		if (!StackWalk(MachineType, hProcess, hThread, &sf, pContext, 0, SymFunctionTableAccess, SymGetModuleBase, 0)) {
		   break;
		}
		if (sf.AddrFrame.Offset == 0) {
		   break;
		}

		BYTE SymbolBuffer[sizeof(SYMBOL_INFO) + 1024];
		PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)SymbolBuffer;

		pSymbol->SizeOfStruct = sizeof(SymbolBuffer);
		pSymbol->MaxNameLen = 1024;

		if (SymFromAddr(hProcess, sf.AddrPC.Offset, 0, pSymbol)) {
			sprintf(Log, "Function    : %s", pSymbol->Name);
			LoggerAddLog("DumpInfo", Log);
		}
		else {
			LoggerAddLog("DumpInfo", "Function    : Unknown");
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
			LoggerAddLog("DumpInfo", "Source File : Unknown");
			LoggerAddLog("DumpInfo", "Source Line : Unknown");
		}
	}
}

#endif
