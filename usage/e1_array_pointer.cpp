#include <stdio.h>

int find_max(int *arr, int size){
    if(size <= 0){
        return 0;
    }
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}


// This is can pass array as the argument
// But to initilize array, you still need to use a constant value (5)
int main(){
    int arr[5] = {1,2,3,4,5};
    printf("Max is %d\n", find_max(arr, 5));
}