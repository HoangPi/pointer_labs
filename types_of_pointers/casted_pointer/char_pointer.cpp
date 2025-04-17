#include <stdio.h>

int main(){
    __int64_t x = 0x217265746e696f50;
    char *ptr = (char *)&x;
    for (int i = 0; i < sizeof(__int64_t); i++)
    {
        printf("%c", ptr[i]);
    }
    printf("\n");
}