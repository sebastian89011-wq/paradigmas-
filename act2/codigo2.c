#include <stdio.h>
#include <stdlib.h>

int* allocate_memory() {
    int *arr = (int *)malloc(5 * sizeof(int));

    if(arr == NULL)
    {
        printf("\nerror de memoria");
        return;
    }
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 2;
    }
    printf("arr[2]: %d\n", arr[2]);

    return arr;
}

int main() {
    int* arr;
    arr = allocate_memory();
    free(arr);
    return 0;
}