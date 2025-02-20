#include <stdio.h>

typedef struct {
    int id_loja[100];
    int id_produto[100];
} Loja;

void cadastrarLojas(Loja *lojas, int qntLojas){
    for(int i = 0; i < qntLojas; i++){
        scanf("%d", &lojas->id_loja[i]);
        if(lojas->id_loja[i] > 100){
            printf("ID da loja inválido! Insira novamente:\n");
            i--; 
            continue;
        }
        scanf("%d", &lojas->id_produto[i]);
        if(lojas->id_produto[i] > 50){
            printf("ID do produto inválido! Insira novamente:\n");
            i--;
        }
    }
}

void printLojas(Loja *lojas, int tam){
    for (int i = 0; i < tam; i++) 
        printf("LOJA %d COM O PRODUTO %d\n", lojas->id_loja[i], lojas->id_produto[i]);
}

int Particion(Loja* lojas, int left, int right){
    int i = left - 1;
    int pivot = lojas->id_loja[right];

    for(int j = left; j < right; j++){
        if((lojas->id_loja[j] < pivot) || (lojas->id_loja[j] == pivot && lojas->id_produto[j] < lojas->id_produto[right])){
            i++;
            int temp = lojas->id_loja[i];
            lojas->id_loja[i] = lojas->id_loja[j];
            lojas->id_loja[j] = temp;

            int temp1 = lojas->id_produto[i];
            lojas->id_produto[i] = lojas->id_produto[j];
            lojas->id_produto[j] = temp1;
        }
    }
    int temp = lojas->id_loja[i+1];
    lojas->id_loja[i+1] = lojas->id_loja[right];
    lojas->id_loja[right] = temp;

    int temp1 = lojas->id_produto[i+1];
    lojas->id_produto[i+1] = lojas->id_produto[right];
    lojas->id_produto[right] = temp1;

    return i + 1;
}

void QuickSort(Loja* lojas, int left, int right){
    if(left < right){
        int pivot = Particion(lojas, left, right);
        QuickSort(lojas, left, pivot - 1);
        QuickSort(lojas, pivot + 1, right);
    }
}

int main(){
    Loja lojas; 

    int qntLojas;
    scanf("%d", &qntLojas);

    cadastrarLojas(&lojas, qntLojas);   
    printf("LOJAS INICIAIS:\n");
    printLojas(&lojas, qntLojas);

    QuickSort(&lojas, 0, qntLojas - 1);

    printf("LOJAS ORDENADAS:\n");
    printLojas(&lojas, qntLojas);

    return 0;
}
