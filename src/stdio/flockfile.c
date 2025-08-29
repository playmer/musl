#include "stdio_impl.h"
#ifndef WIN32
#include "pthread_impl.h"
#else
#include "win32_thread_impl.h"
#endif

void flockfile(FILE *f)
{
	if (!ftrylockfile(f)) return;
	__lockfile(f);
	__register_locked_file(f, __pthread_self());
}
