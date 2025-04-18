#include <iostream>

using namespace std;

void func3(void **adr)
{
    cout << "This is function 3\n";
    *adr = nullptr;
}

void func2(void **adr)
{
    cout << "This is function 2\n";
    *adr = (void **)func3;
}

void func1(void **adr)
{
    cout << "This is function 1\n";
    *adr = (void **)func2;
}

int main()
{
    void (*f)(void **);
    f = func1;
    while (f != nullptr)
    {
        f((void **)&f);
    }
    
}