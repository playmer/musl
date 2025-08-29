
#ifndef WIN32
#include <pthread.h>
#else
#include "win32_thread_impl.h"
#endif
#include <threads.h>

int mtx_init(mtx_t *m, int type)
{
#ifndef WIN32
	*m = (mtx_t){
		._m_type = ((type&mtx_recursive) ? PTHREAD_MUTEX_RECURSIVE : PTHREAD_MUTEX_NORMAL),
	};
	return thrd_success;
#else
#include "win32_thread_impl.h"
#endif
}
