#include <stdio.h>

void BinSort(int* arr, int tam, int i) {
    if (i >= tam) {
        return;
    }

    // Coloca arr[i] na posição correta, se possível
    while (arr[i] != i && arr[i] < tam) {
        int t = arr[i];
        arr[i] = arr[t];
        arr[t] = t;
    }

    BinSort(arr, tam, i + 1);
}

int main() {
    int arr[] = {5, 3, 2, 4, 1};  
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    BinSort(arr, tamanho, 0);

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
}
