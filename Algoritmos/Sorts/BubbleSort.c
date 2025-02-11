#include <stdio.h>

void BubbleSort(int* arr, int tam){
    for(int i = 0; i <= tam; i++){
        for(int j = 0; j <= tam - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

int main(){
    int arr[] = {2,33,1,5,21,444};
    int tam = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,tam-1);

    for(int i = 0; i <= tam - 1; i++){
        printf("%d ", arr[i]);
    }
}