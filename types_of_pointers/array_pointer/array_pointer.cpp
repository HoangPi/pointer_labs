#include <stdio.h>

int main(){
    int arr[5] = {1,2,3,4,5};
    int *ptr = arr;
    for (int i = 0; i < 5; i++)
    {
        // You can un-comment one of the command 

        printf("%d ", arr[i]);
        // printf("%d ", *(arr + i));
        // printf("%d ", ptr[i]);
        // printf("%d ", *(ptr + i));
    }
    printf("\nAddress of arr is %p", &arr);
    printf("\nValue   of arr is %p\n", arr);
}