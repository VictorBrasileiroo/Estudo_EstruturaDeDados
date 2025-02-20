#include <stdio.h>

void InsertSort(int* arr, int tam) {
    for (int i = 1; i < tam; i++) {  
        int j = i;
        while (j > 0 && arr[j] <= arr[j-1]) {  
            int t = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = t;
            j--;
        }
    }
}

int main() {
    int array[] = {21, 5, 5, 34};
    int tam = sizeof(array) / sizeof(array[0]);  // Tamanho correto do array
    InsertSort(array, tam);
    
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
