#pragma once

#include <threads.h>

#include <syscall.h>

struct __thrd_t
{
    thrd_start_t func;
    void *arg;
	HANDLE thread_handle;
    DWORD thread_id;
};

int __win32_thrd_create(thrd_t *thr, thrd_start_t func, void *arg);
_Noreturn void __win32_thrd_exit(int result);


int __win32_mtx_init(mtx_t *, int);
void __win32_mtx_destroy(mtx_t *);

int __win32_mtx_lock(mtx_t *);
int __win32_mtx_timedlock(mtx_t *__restrict, const struct timespec *__restrict);
int __win32_mtx_trylock(mtx_t *);
int __win32_mtx_unlock(mtx_t *);

int __win32_cnd_init(cnd_t *);
void __win32_cnd_destroy(cnd_t *);

int __win32_cnd_broadcast(cnd_t *);
int __win32_cnd_signal(cnd_t *);

int __win32_cnd_timedwait(cnd_t *__restrict, mtx_t *__restrict, const struct timespec *__restrict);
int __win32_cnd_wait(cnd_t *, mtx_t *);



int __win32_tss_create(tss_t *, tss_dtor_t);
void __win32_tss_delete(tss_t);

int __win32_tss_set(tss_t, void *);
void *__win32_tss_get(tss_t);