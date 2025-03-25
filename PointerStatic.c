#include <stdio.h>

int* getArray() {  
    static int arr[3] = {10, 20, 30};  
    return arr;
}

int main() {
    int *arr = getArray();  
    printf("Array elements: %d %d %d\n", arr[0], arr[1], arr[2]);
    return 0;
}
