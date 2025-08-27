#include <win32/windows.h>

int main()
{
    MessageBoxA(0, "startup_main", "startup_main", MB_CANCELTRYCONTINUE);
    Sleep(1000);
    return 0;
}