#include <stdio.h>

//for para analisar todos os elementos --> 0 até o ultimo
    //crio um j que sempre analisa o posterior de i 
    //enquanto a posição atual for maior do que a posição anterior e maior que zero 
        // --> ele vai trocar com o elemento anterior e diminuir em um

void InsertSort(int* arr, int tam){
    for(int i = 0; i <= tam; i++){
        int j = i + 1;
        while((arr[j] > arr[j-1]) && j > 0){
            int t = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = t;
            j--;
        }
    }
}

int main(){
    int array[] = {21,5,77,34};
    int tam = (sizeof(array)/sizeof(array[0])) - 1;
    InsertSort(array,tam);
    for(int i = 0; i <= tam; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
