#include <stdlib.h>
#include "syscall.h"

_Noreturn void _Exit(int ec)
{
#ifndef WIN32
	__syscall(SYS_exit_group, ec);
	for (;;) __syscall(SYS_exit, ec);
#else
	ExitProcess(ec);
#endif
}
