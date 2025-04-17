#include <stdio.h>

void do_nothing(int i){
    long long *x = new long long;
    if(i % 1000000 == 0){
        printf("Address of x is %p\n", &x); // This will be the same regardless
        printf("value of x is %p\n", x);    // This will increase steadily and cause overflow
    }
}

// Please be very careful when you run the code
// Remember to inspect your RAM when running it
// If your RAM's usage doesn't increase but the program is still running
// It means that it is writing data into you hard drive
// And you have to manually stop the program
int main(){
    for (int i = 0; 1; i++)
    {
        do_nothing(i);
    }
}