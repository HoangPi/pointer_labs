#include <stdio.h>

struct big_struct
{
    long long a;
    long long b;
    long long c;
    long long d;
};

big_struct add1_without_pointer(big_struct x)
{
    // When you return, you also create a copy of that return value
    return big_struct({x.a + 1, x.b + 1, x.c + 1, x.d + 1});

    // Or you can return the one in the argument
    // At least, it doesn't create another copy
    // x.a++;
    // x.b++;
    // x.c++;
    // x.d++;
    // return x;
}

void add1_with_pointer(big_struct *x)
{
    // Using pointer, you go straight to the memory of original data
    // and modify it directly
    x->a++;
    x->b++;
    x->c++;
    x->d++;
}

int main()
{
    big_struct a = {1, 2, 3, 4};
    // You also have to re-asign the variable
    a = add1_without_pointer(a);
    printf("%lld %lld %lld %lld\n", a.a, a.b, a.c, a.d);
    add1_with_pointer(&a);
    printf("%lld %lld %lld %lld\n", a.a, a.b, a.c, a.d);
}