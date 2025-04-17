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


// With this, you can dynamically initilize array with any size
// As long as there is room for it
int main(){
    int size = 5;
    int *arr = new int[3]{1,55,3};
    printf("Max is %d\n", find_max(arr, size));
}