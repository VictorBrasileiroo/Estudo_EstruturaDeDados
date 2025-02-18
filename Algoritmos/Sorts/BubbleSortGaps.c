#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Como funciona o algoritmo de alocação de gaps
//1. primeiro vamos criar um array para armazenar os gaps --> ex: distancia[2,2,4] 
//2. após isso vamos calcular a distancia entre números
//3. calculamos quantos gaps existem --> por isso precisa fazer um acumulador de gaps 
//4. calculamos o novo tamanho do array --> tamanho original + qnt de gaps
//5. alocamos memória com o calloc para criar o array que iniciará com 0 nas posições 
//6. colocamos os elementos em suas devidas posições --> distancias corretas entre eles e zeros entre os elementos
//7. fazemos a transformação do arr original no arr com gaps
//8. liberamos o espaço de memória do arr dos gaps
//9. retornando o tamanho do array ordenado e com gaps

int addGaps(int* arr, int tam){
    int distancia[tam-1];  
    for(int i = 0; i < tam-1; i++){
        if(arr[i] == arr[i+1]){
            distancia[i] = 0; 
        }else{
            distancia[i] = (arr[i + 1] - arr[i]) - 1;  
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
    
    return 0;
}