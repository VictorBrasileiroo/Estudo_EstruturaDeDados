#include <stdio.h>

//essa função aqui só serve para encontrar o menor valor de um array
int BuscarMenor(int arr[], int inicio, int tam){
    int menorIndex = inicio;

    //percorre o array a partir do inicio --> inicio + 1 pois o inicio já é o menor
    for(int i = inicio + 1; i < tam; i++){
        if(arr[menorIndex] > arr[i]){
            menorIndex = i;
        }
    }
    //retorna o index do menor valor
    return menorIndex;
}

//essa função aqui é a função de ordenação por seleção --> ela vai tanto adicionar o menor valor no novo array quanto trocar o menor valor de lugar com o valor que está na posição atual
void OrdenacaoSelecao(int arr[], int tam, int arrayOrdenado[]){
    //percorre o array
    for(int i = 0; i < tam; i++){
        //encontra o indice do menor valor --> PS: O INICIO VAI MUDANDO AO DECORRER DO LOOP
        int menorIndice = BuscarMenor(arr, i ,tam);
        //adiciona o menor valor no novo array
        arrayOrdenado[i] = arr[menorIndice];
        //troca o menor valor de lugar com o valor que está na posição atual
        int temp = arr[menorIndice];
        arr[menorIndice] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int lista[5] = {5, 3, 6, 2, 10};
    int arrayOrdenado[5];

    OrdenacaoSelecao(lista, 5, arrayOrdenado);

    // Exibir array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arrayOrdenado[i]);
    }
    printf("\n");

    return 0;
}