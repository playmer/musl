#include <stdarg.h>
#include <win32/windows.h>

extern "C"
{

//extern "C" int main(int argc, char** argv);
int main();

using GlobalInitializerFn = void(__cdecl *)();

////////
// We need to get a table of global initializers and run them, documented here:
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/crt-initialization?view=msvc-170
#pragma section(".CRT$XCA", read, write)
#pragma data_seg(".CRT$XCA")
GlobalInitializerFn __gGlobalInitializerStart[] = {0};

#pragma section(".CRT$XCZ", read, write)
#pragma data_seg(".CRT$XCZ")
GlobalInitializerFn __gGlobalInitializerEnd[] = {0};

void RunGlobalInitializers()
{
    for (GlobalInitializerFn* fn = __gGlobalInitializerStart; fn < __gGlobalInitializerEnd; ++fn)
    {
        if (*fn != nullptr) 
        {
            (*fn)();
        }
    }
}

int mainCRTStartup(void)
{
    RunGlobalInitializers();

    MessageBoxA(0, "Weeee", "wooooo", MB_CANCELTRYCONTINUE);
    int ret = main();
    ExitProcess(ret);
    return ret;
}

}
