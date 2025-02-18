#include <stdio.h>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        if(i != size - 1) {
            printf("%d -> ", arr[i]);
        } else {
            printf("%d\n", arr[i]);
        }
    }
}

int getMax(int* arr, int tam) {
    int max = arr[0];
    for (int i = 1; i < tam; i++) {
        if (arr[i] > max)max = arr[i];
    }
    return max;
}

void radixBubbleSort(int* arr, int tam) {
    int max = getMax(arr, tam);
    int exp = 1;
    
    while (max/exp > 0) {
        for (int i = 0; i < tam - 1; i++){
            for (int j = 0; j < tam - 1 - i; j++){
                int v1 = (arr[j] / exp) % 10;
                int v2 = (arr[j+1] / exp) % 10;
                if (v1 > v2){
                    int t = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = t;
                }
            }
        }
        exp *= 10;
    }
}

int main(){
    int arr[] = {11,231,2,51,3,1};
    int tam = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,tam);
    radixBubbleSort(arr,tam);
    printArray(arr,tam);
    return 0;
}