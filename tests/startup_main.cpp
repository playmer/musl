#include <win32/windows.h>

struct Animal {
    virtual ~Animal() = 0;
    virtual void Speak() = 0;
};

struct Cat : public Animal {
    ~Cat(){};
    virtual void Speak() override {
         MessageBoxA(0, "meow", "meow", MB_CANCELTRYCONTINUE);
    }
};

// class Test {
//     int* t;
// public:
//     Test(int a) 
//     {
//         t = new int(a);
//         MessageBoxA(0, "Test()", "Test()", MB_CANCELTRYCONTINUE);
//     }
//     ~Test()
//     {
//         delete t;
//         MessageBoxA(0, "~Test()", "~Test()", MB_CANCELTRYCONTINUE);
//     }
// };
//const Test t2 = Test(5);

int test_global_init()
{
    MessageBoxA(0, "test_global_init", "test_global_init", MB_CANCELTRYCONTINUE);
    return 1;
}

const int t1 = test_global_init();

int main()
{
    MessageBoxA(0, "startup_main", "startup_main", MB_CANCELTRYCONTINUE);
    Animal* animal = new Cat();
    delete animal;
    Sleep(1000);
    return 0;
}