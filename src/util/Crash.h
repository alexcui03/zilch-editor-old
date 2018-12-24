#ifndef CRASH_H
#define CRASH_H

#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void ConvertNumberBin64(char *Buffer, uint64_t Value);
void ConvertNumberBin32(char *Buffer, uint32_t Value);
void ConvertNumberBin16(char *Buffer, uint16_t Value);
void ConvertNumberBin8(char *Buffer, uint8_t Value);
void OutputCPUStatus64(char *Buffer, const char *Name, uint64_t Value);
void OutputCPUStatus32(char *Buffer, const char *Name, uint32_t Value);
void OutputCPUStatus16(char *Buffer, const char *Name, uint16_t Value);

void BindCrashHandler(void);

#ifdef __cplusplus
}
#endif

#endif // CRASH_H
