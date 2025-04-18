#include <stdio.h>

int main(){
    long long x = 0x217265746e696f50;
    char *ptr = (char *)&x;
    for (int i = 0; i < sizeof(long long); i++)
    {
        printf("%c", ptr[i]);
    }
    printf("\n");
}