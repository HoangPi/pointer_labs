#include <stdio.h>

struct big_struct{
    long long a;
    long long b;
    long long c;
    long long d;
};

void without_pointer(big_struct a){
    // Passing data without using pointer will create a copy of that data
    printf("Size of data is %ld\n", sizeof(a));
    printf("%lld %lld %lld %lld\n", a.a, a.b, a.c, a.d);
}
void with_pointer(big_struct *a){
    // Using pointer does not create a copy of data
    // You are refering to the original data using a pointer that point to it
    printf("Size of data is %ld\n", sizeof(a));
    // The syntax is a bit different but intellisense can help you with it
    printf("%lld %lld %lld %lld\n", a->a, a->b, a->c, a->d);
}

int main(){
    big_struct a = {1,2,3,4};
    without_pointer(a);
    with_pointer(&a);
}