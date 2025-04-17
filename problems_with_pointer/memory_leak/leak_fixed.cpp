#include <stdio.h>
#include <thread>
#include <chrono>

void do_nothing(int i)
{
    long long *x = new long long;
    if (i % 1000000 == 0)
    {
        printf("Address of x is %p\n", &x); // This will be the same regardless
        printf("value of x is %p\n", x);    // This will increase steadily and cause overflow
    }
    delete x;
}
void delayed_stop(int *stop_flag)
{
    // You decide how long this should take
    int sec = 3;
    std::this_thread::sleep_for(std::chrono::seconds(sec));
    *stop_flag = 1;
}

int main()
{
    int stop = 0;
    std::thread task(delayed_stop, &stop);
    for (int i = 0; 1; i++)
    {
        if(stop == 1){
            printf("Process is stopped\n");
            break;
        }
        do_nothing(i);
    }
    task.join();
}