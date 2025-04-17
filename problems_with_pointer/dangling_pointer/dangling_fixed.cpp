#include <stdio.h>

int main(){
    int *x = new int(8);
    printf("Value at x is %d\n", *x);
    delete x;
    x = nullptr;
    if(x != nullptr){
        printf("Value at x is %d\n", *x);
        new int(44);
        printf("Value at x is %d\n", *x);
    }
}