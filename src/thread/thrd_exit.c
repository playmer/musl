#include <threads.h>
#include <stdint.h>

#ifndef WIN32
#include <pthread.h>
#else
#include "win32_thread_impl.h"
#endif

_Noreturn void thrd_exit(int result)
{
	
#ifndef WIN32
	__pthread_exit((void*)(intptr_t)result);
#else
	__win32_thrd_exit(result);
#endif
}
