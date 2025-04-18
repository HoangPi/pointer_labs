#include <stdio.h>

int main(){
    // ASCII code
    // 0x21 = !
    // 0x72 = r
    // 0x65 = e
    // 0x74 = t
    // 0x6e = n
    // 0x69 = i
    // 0x6f = o
    // 0x50 = P
    long long x = 0x217265746e696f50;
    char *ptr = (char *)&x;
    for (int i = 0; i < sizeof(long long); i++)
    {
        printf("%c", ptr[i]);
    }
    printf("\n");
}