#include <iostream>

void add1(int *ptr)
{
    int *copy = ptr;
    (*copy)++;
    printf("New value is %d\n", *ptr);
    delete copy;
    copy = nullptr;
}

int main()
{
    int *ptr = new int(66);
    printf("Value at ptr is %d\n", *ptr);
    add1(ptr);
    printf("Value at ptr is %d\n", *ptr);
    delete ptr;
    ptr = nullptr;
}