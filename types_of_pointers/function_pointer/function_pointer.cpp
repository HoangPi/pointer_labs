#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
void do_thing(int a, int b, int (*f)(int, int)){
    printf("Result in do_thing is %d\n", f(a, b));
}

int main()
{
    int a = 7, b = 4;
    int (*f)(int, int);
    f = add;
    printf("Result is %d\n", f(a, b));

    f = sub;
    do_thing(a, b, sub);
    do_thing(a, b, f);
}