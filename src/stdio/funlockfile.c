#include "stdio_impl.h"
#ifndef WIN32
#include "pthread_impl.h"
#else
#include "win32_thread_impl.h"
#endif

void funlockfile(FILE *f)
{
	if (f->lockcount == 1) {
		__unlist_locked_file(f);
		f->lockcount = 0;
		__unlockfile(f);
	} else {
		f->lockcount--;
	}
}
