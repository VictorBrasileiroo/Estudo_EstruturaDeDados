#include <stdio.h>

int BubbleSort(int* arr, int tam){
    int qntLoops = 0;
    for(int i = 0; i <= tam; i++){
        for(int j = 0; j <= tam - 1 - i; j++){
            if(arr[j] >= arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
        qntLoops++;
    }
    return qntLoops;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int tam = sizeof(arr)/sizeof(arr[0]);
    int qnt = BubbleSort(arr,tam-1);

    for(int i = 0; i <= tam - 1; i++){
        printf("%d ", arr[i]);
    }

    printf("QNT DE OPERAÇÕES: %d", qnt);
}

int inserirValor(double* arr, int tam, double value){
    for(int i = 0; i < tam; i++){
        if(arr[i] < value && arr[i+1] == 0){
            arr[i+1] = value;
        }
    }

    int newTam = addGaps(arr,tam);
    return newTam;
}

void removerValor(double* arr, int tam, double value){
    for(int i = 0; i < tam; i++){
        if(arr[i] == value){
            arr[i] = 0;
        }
    }
}