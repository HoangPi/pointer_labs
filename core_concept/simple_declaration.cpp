#include <stdio.h>

int main(){
    int x = 7;
    printf("Value of x is     %d\n", x);
    printf("Address of x is   %p\n", &x);
    int *ptr = &x;
    printf("Value of ptr is   %p\n", ptr);
    printf("Address of ptr is %p\n", &ptr);
    printf("Value at ptr is   %d\n", *ptr);
}