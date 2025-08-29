#include <stdlib.h>
#include <syscall.h>
#include "win32_thread_impl.h"


static DWORD WINAPI thread_trampoline( LPVOID lpParam )
{
    thrd_t thread_data = (thrd_t)lpParam;
    return thread_data->func(thread_data->arg);
}

int __win32_thrd_create(thrd_t *thr, thrd_start_t func, void *arg)
{
    *thr = calloc(1, sizeof(struct __thrd_t));
    DWORD thread_id = 0;
    (*thr)->func = func;
    (*thr)->arg = arg;

	HANDLE thread_handle = CreateThread( 
            NULL,                   // default security attributes
            0,                      // use default stack size  
            thread_trampoline,       // thread function name
            arg,          // argument to thread function 
            0,                      // use default creation flags 
            &(*thr)->thread_id);   // returns the thread identifier 

	return thrd_error;
}

_Noreturn void __win32_thrd_exit(int result)
{
    ExitThread(result);
}


int __win32_tss_create(tss_t *, tss_dtor_t)
{

}

void __win32_tss_delete(tss_t)
{
    
}

int __win32_tss_set(tss_t id, void *value)
{
    TlsSetValue(id, value);
}

void *__win32_tss_get(tss_t id)
{
    return TlsGetValue(id);
}


int __win32_mtx_init(mtx_t *mutex, int);
void __win32_mtx_destroy(mtx_t *mutex)
{

}
