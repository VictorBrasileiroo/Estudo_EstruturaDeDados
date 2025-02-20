#include <stdio.h>
#include <stdlib.h>

int addGaps(int* arr, int tam){
    int distancia[tam-1];  
    for(int i = 0; i < tam-1; i++){
        if(arr[i] == arr[i+1]){
            distancia[i] = 0; 
        }else{
            distancia[i] = arr[i + 1] - arr[i] - 1;  
        }
    }

    int soma = 0;
    for(int i = 0; i < tam-1; i++) soma += distancia[i];

    int tamGap = tam + soma; 
    int* output = (int*)calloc(tamGap, sizeof(int));

    int loc = 0;
    for(int i = 0; i < tam-1; i++){
        output[loc] = arr[i];
        loc += distancia[i] + 1; 
    }
    output[loc] = arr[tam-1]; 

    for(int i = 0; i < tamGap; i++) arr[i] = output[i];
    
    free(output);
    return tamGap;
}

int bubbleSort(int* arr, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam - 1 - i; j++){
            if(arr[j] >= arr[j+1]){  
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }

    int tamArr = addGaps(arr,tam);
    return tamArr;
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        if(i != size - 1) {
            printf("%d -> ", arr[i]);
        } else {
            printf("%d\n", arr[i]);
        }
    }
}

int inserirValor(int* arr, int tam, int value){
    for(int i = 0; i < tam; i++){
        if(arr[i] < value && arr[i+1] == 0){
            arr[i+1] = value;
        }
    }

    int newTam = addGaps(arr,tam);
    return newTam;
}

void removerValor(int* arr, int tam, int value){
    for(int i = 0; i < tam; i++){
        if(arr[i] == value){
            arr[i] = 0;
        }
    }
}

int main(){
    int arr[999];
    int qntnums;
    scanf("%d", &qntnums);

    for(int i = 0; i < qntnums; i++) scanf("%d",&arr[i]);
    printf("ARRAY PRIMÁRIO:\n");
    printArray(arr, qntnums);

    int tamanhoNovo = bubbleSort(arr,qntnums);
    printf("ARRAY ORDENADO:\n");
    printArray(arr, tamanhoNovo);

    int valorInserido;
    printf("DIGITE O VALOR A SER INSERIDO:\n");
    scanf("%d", &valorInserido);
    int newTam = inserirValor(arr,tamanhoNovo,valorInserido);
    printArray(arr,newTam);

    int valorInserido2;
    printf("DIGITE O VALOR A SER ELIMINADO:\n");
    scanf("%d", &valorInserido2);
    removerValor(arr,tamanhoNovo,valorInserido2);
    printArray(arr,newTam);

    return 0;
}