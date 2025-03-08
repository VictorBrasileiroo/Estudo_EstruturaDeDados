#include <stdio.h>
#include <limits.h> // Para usar INT_MAX

void mergeSort(int* arr, int start, int end){
    if(start < end){
        int meio = (start + end)/2;
        mergeSort(arr,start,meio);
        mergeSort(arr,meio+1,end);
        merge(arr,start,meio,end);
    }
}

void merge(int A[], int start, int meio, int end) {
    int n1 = meio - start + 1; // tamanho do inicio ao meio
    int n2 = end - meio; // tamanho do meio ao fim

    //criação dos arrays auxiliares
    int L[n1 + 1], R[n2 + 1];

    //transferencia dos valores para os arratas auxiliares
    for (int i = 0; i < n1; i++)
        L[i] = A[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[meio + 1 + j];

    // Adicionando sentinelas
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    // Mesclando os arrays de volta em A[p..r]
    for (int k = start; k <= end; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

// Função auxiliar para imprimir um array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Testando a função de mesclagem
int main() {
    int A[] = {12,3,22}; 
    int p = 0, r = 2;

    printf("Array antes da mesclagem:\n");
    printArray(A, 3);

    mergeSort(A, p, r);

    printf("Array depois da mesclagem:\n");
    printArray(A, 3);

    return 0;
}