#ifndef WIN32
#include "pthread_impl.h"
#else
#include "win32_thread_impl.h"
#endif
#include <threads.h>

int thrd_create(thrd_t *thr, thrd_start_t func, void *arg)
{
#ifndef WIN32
	int ret = __pthread_create(thr, __ATTRP_C11_THREAD, (void *(*)(void *))func, arg);
	switch (ret) {
	case 0:      return thrd_success;
	case EAGAIN: return thrd_nomem;
	default:     return thrd_error;
	}
#else
	return __win32_thrd_create(thr, func, arg);
#endif

}
