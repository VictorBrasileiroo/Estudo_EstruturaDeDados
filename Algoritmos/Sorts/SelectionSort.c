#include <stdio.h>

int MenorIndex(int* arr, int tam, int inicio){
    int menorIndex = inicio;
    for(int i = inicio; i <= tam - 1; i++){
        if(arr[i] < arr[menorIndex]){
            menorIndex = i;
        }
    }
    return menorIndex;
}

void SelectionSort(int* arr, int tam){
    for(int j = 0; j <= tam - 1; j++){
       int menor = MenorIndex(arr,tam,j);
       int temp = arr[menor];
       arr[menor] = arr[j];
       arr[j] = temp;
    }
}

int main(){
    int numeros[] = {3,2,1,25,222,12,1};
    int tam = sizeof(numeros) / sizeof(numeros[0]);
    SelectionSort(numeros,tam);
    for(int i = 0; i <= tam - 1; i++){
        printf("%d ", numeros[i]);
    }
    return 0;
}