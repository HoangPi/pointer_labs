#include <iostream>

int add(int a, int b)
{
    return a + b;
}

// Normally, when you have a pointer,
// you will need to specify what data type the pointer is pointing at
// so that the compiler can understand how much data to retrieve from that address
// and how to format the data correctly.

// Using void pointer, you only tell the compiler where the data BEGINS
// compiler doesn't know where the data end or even how to format it
// but the main benefit of void pointer is that it can point to anywhere
int main()
{
    void *ptr;
    int a = 45;
    long long b = 25l;
    float c = 2.7f;
    double d = 7.99999;

    // To use, you must cast the pointer into a specific data type
    // to tell compiler how to deal with it
    // syntax is shrimple
    // (<your_data_type>)<your_variable>
    // Because you want to cast you void pointer into like int pointer,
    // you need to include * in () and * on the far left to dereference that casted poniter
    ptr = &a;
    printf("Integer is      %d\n", *(int *)ptr);
    // although it got the address, the compiler though it is just a normal integer (not pointer)
    // So trying to dereference that "false cast" causes compiling error
    printf("False cast is   %lx\n", (int)ptr);
    printf("Address of a is %p\n", &a);
    // printf("False cast is   %lx\n", *(int)ptr); //This is false

    // This cast address into long long value, that casted value then is casted once more into int pointer
    // then dereference that int pointer
    // Please dont do this at anywhere
    printf("False cat is    %d\n", *(int *)(long long)ptr); 

    ptr = &b;
    printf("Long long is    %lld\n", *(long long *)ptr);

    ptr = &c;
    printf("Float is        %.2f\n", *(float *)ptr);

    ptr = &d;
    printf("Double is       %.5f\n", *(double *)ptr);

    // If you are unfamiliar with casting function, you can declare a temporary function pointer
    // wait for intellisense to validate your declarartion
    // copy the whole declare (minus the ";") and put it into the cast block
    // then remove the name (temp)
    // also remember to wrap your pointer and cast block in another ()
    int (*temp)(int, int);
    ptr = &add;
    printf("Add is          %d\n", ((int (*)(int, int))ptr)(a, int(b)));
}