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

void printLojas(Loja *Lojas, int tam){
    for (int i = 0; i < tam; i++) printf("LOJA %d COM O PRODUTO %d\n", Lojas->id_loja[i], Lojas->id_produto[i]);
}

void InsertionSortLojas(Loja *lojas, int tam){
    for (int i = 1; i < tam; i++){
        int j = i;
        while (j > 0 && 
            (lojas->id_loja[j] > lojas->id_loja[j-1] ||
            (lojas->id_loja[j] == lojas->id_loja[j-1] 
            && lojas->id_produto[j] >= lojas->id_produto[j-1]))) 
            {

            int t = lojas->id_loja[j];
            lojas->id_loja[j] = lojas->id_loja[j-1];
            lojas->id_loja[j-1] = t;

            int h = lojas->id_produto[j];
            lojas->id_produto[j] = lojas->id_produto[j-1];
            lojas->id_produto[j-1] = h;
            j--;
            
        }
    }
}


int main(){
    Loja lojas;

    int qntLojas;
    scanf("%d", &qntLojas);

    cadastrarLojas(&lojas, qntLojas);   
    
    printf("LOJAS INICIAIS:\n");
    printLojas(&lojas, qntLojas);

    InsertionSortLojas(&lojas,qntLojas);

    printf("LOJAS ORDENADAS:\n");
    printLojas(&lojas, qntLojas);
}