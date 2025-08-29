#include <win32/windows.h>

int test_global_init()
{
    MessageBoxA(0, "test_global_init", "test_global_init", MB_CANCELTRYCONTINUE);
    return 1;
}

const int t1 = test_global_init();

int main()
{
    MessageBoxA(0, "startup_main", "startup_main", MB_CANCELTRYCONTINUE);
    Sleep(1000);
    return 0;
}