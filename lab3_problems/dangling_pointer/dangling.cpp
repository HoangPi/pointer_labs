#include <stdio.h>

int main(){
    int *x = new int(8);
    printf("Value at x is %d\n", *x);
    delete x;
    // g++ will continue but msvc will explode and die
    printf("Value at x is %d\n", *x);
    new int(44);
    printf("Value at x is %d\n", *x);
}