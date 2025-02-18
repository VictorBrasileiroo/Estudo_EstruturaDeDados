#include <stdio.h>

int bubbleSort(int* arr, int tam){
    int qntLoops = 0;
    int trocou;
    for(int i = 0; i < tam; i++){
        trocou = 0;
        for(int j = 0; j < tam - 1 - i; j++){
            if(arr[j] >= arr[j+1]){
                trocou = 1;
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
        qntLoops++;
        if(!trocou)break;
    }

    return qntLoops;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int tam = sizeof(arr)/sizeof(arr[0]);
    
    printf("Array original:\n");
    for(int i = 0; i < tam; i++)
        printf("%d ", arr[i]);
        
    int qnt = bubbleSort(arr, tam);
    
    printf("\nArray ordenado:\n");
    for(int i = 0; i < tam; i++)
        printf("%d ", arr[i]);
        
    printf("QNT DE OPERAÇÕES: %d", qnt);
    return 0;
}