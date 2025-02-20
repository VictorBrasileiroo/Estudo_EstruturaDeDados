#include <stdio.h>

typedef struct {
    int id_loja[100];
    int id_produto[100];
} Loja;

void cadastrarLojas(Loja *lojas, int qntLojas){
    for(int i = 0; i < qntLojas; i++){
        scanf("%d", &lojas->id_loja[i]);
        if(lojas->id_loja[i] > 100){
            i--;
        }
        scanf("%d", &lojas->id_produto[i]);
        if(lojas->id_produto[i] > 50){
            i--;
        }
    }
}

void bubbleSort(Loja *lojas, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam - 1 - i; j++){
            if((lojas->id_loja[j] > lojas->id_loja[j+1]) || (lojas->id_loja[j] == lojas->id_loja[j+1] && lojas->id_produto[j] >= lojas->id_produto[j+1])){

                int t = lojas->id_loja[j];
                lojas->id_loja[j] = lojas->id_loja[j+1];
                lojas->id_loja[j+1] = t;

                int h = lojas->id_produto[j];
                lojas->id_produto[j] = lojas->id_produto[j+1];
                lojas->id_produto[j+1] = h;
                
            }
        }
    }
}

void printLojas(Loja *Lojas, int tam){
    for (int i = 0; i < tam; i++) printf("LOJA %d COM O PRODUTO %d\n", Lojas->id_loja[i], Lojas->id_produto[i]);
}

int main(){
    Loja lojas;

    int qntLojas;
    scanf("%d", &qntLojas);

    cadastrarLojas(&lojas, qntLojas);   
    
    printf("LOJAS INICIAIS:\n");
    printLojas(&lojas, qntLojas);

    bubbleSort(&lojas, qntLojas);
    printf("\n");

    printf("LOJAS ORDENADAS:\n");
    printLojas(&lojas, qntLojas);
    return 0;
}
