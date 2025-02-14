#include <stdio.h>
#include <stdlib.h>

int getMax(int* arr, int tam) {
    int max = arr[0];
    for (int i = 1; i < tam; i++) {
        if (arr[i] > max)max = arr[i];
    }
    return max;
}

void radixSort(int* arr, int tam){
    int max = getMax(arr, tam);
    int exp = 1;
    int output[tam];

    while (max / exp > 0){
        int count[10] = {0};

        for (int i = 0; i < tam; i++) count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++) count[i] += count[i - 1];

        for (int i = tam - 1; i >= 0; i--){
            int digito = (arr[i] / exp) % 10;
            output[count[digito] - 1] = arr[i];
            count[digito]--;
        }

        for (int i = 0; i < tam; i++) arr[i] = output[i];
        
        exp *= 10;
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int tam = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < tam; i++) printf("%d ", arr[i]);
    printf("\n");

    radixSort(arr, tam);

    printf("Array ordenado:\n");
    for (int i = 0; i < tam; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
