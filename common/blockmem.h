#pragma once

#include "cmdlib.h" //--vluzacn

extern void* AllocBlock(unsigned long size);
extern bool FreeBlock(void* pointer);

extern void* Alloc(unsigned long size);
extern bool Free(void* pointer);

#if defined(CHECK_HEAP)
extern void HeapCheck();
#else
#define HeapCheck()
#endif
