#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int start, int middle, int end) {
    int tam = end - start + 1;
    int p1 = start;
    int p2 = middle + 1;
    int fim1 = 0, fim2 = 0;
    int *temp = (int*)malloc(tam * sizeof(int));

    if (temp != NULL) {
        for (int i = 0; i < tam; i++) {
            if (!fim1 && !fim2) {
                if (arr[p1] < arr[p2]) {
                    temp[i] = arr[p1++];
                } else {
                    temp[i] = arr[p2++];
                }

                if (p1 > middle) fim1 = 1;
                if (p2 > end) fim2 = 1;
            } else {
                if (!fim1) {
                    temp[i] = arr[p1++];
                } else {
                    temp[i] = arr[p2++];
                }
            }
        }

        for (int i = 0, j = start; i < tam; i++, j++) {
            arr[j] = temp[i];
        }
    }

    free(temp);
}

void mergeSort(int* arr, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}

void printArr(int* arr, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d --> ", arr[i]);
    }
    printf("NULL\n");
}

int main() {
    int arr[] = {32, 5, 1, 23, 4};
    int end = sizeof(arr) / sizeof(arr[0]);
    
    printArr(arr, end);
    mergeSort(arr, 0, end - 1);
    printArr(arr, end);
    
    return 0;
}
