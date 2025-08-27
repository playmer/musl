#include <stdarg.h>
#include <win32/windows.h>

//extern "C" int main(int argc, char** argv);
int main();

int mainCRTStartup(void)
{
    MessageBoxA(0, "Weeee", "wooooo", MB_CANCELTRYCONTINUE);
    int ret = main();
    ExitProcess(ret);
    return ret;
}