#include <stdio.h>

void BinSort(int* arr, int tam, int i) {
    while (i < tam) {  
        if (arr[i] == i + 1){  // + 1 pois começa em 0
            i++;
        }else{
            int t = arr[i] - 1;  // - 1 pois o indice vai de 0 a 4 (ex)
            int temp = arr[i];
            arr[i] = arr[t];
            arr[t] = temp;
        }
        //arr[arr[i]] <--> arr[i]
    }
}

int main(){
    int arr[] = {5, 3, 2, 4, 1};  
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    BinSort(arr, tamanho, 0);

    for (int i = 0; i < tamanho; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
