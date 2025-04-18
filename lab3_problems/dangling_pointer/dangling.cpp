#include <stdio.h>

int main(){
    int *x = new int(8);
    printf("Value at x is %d\n", *x);
    delete x;
    printf("Value at x is %d\n", *x);   // This will give you undefined result
    // 44 will occupy the old space because that space is freshly freed so why not
    // even if you don't re-asign the pointer
    new int(44);
    printf("Value at x is %d\n", *x);
}