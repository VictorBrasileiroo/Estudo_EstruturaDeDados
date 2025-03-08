#include <stdio.h>

typedef struct {
    int id_loja;
    int id_produto;
} Loja;

void BubbleSort(Loja* lojas, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam - 1 - i; j++){
            if(
                (lojas[j].id_loja >= lojas[j+1].id_loja) ||
                (lojas[j].id_loja == lojas[j+1].id_loja &&
                lojas[j].id_produto >= lojas[j+1].id_produto)
            ){
                int t = lojas[j].id_loja;
                lojas[j].id_loja = lojas[j+1].id_loja;
                lojas[j+1].id_loja = t;

                int h = lojas[j].id_produto;
                lojas[j].id_produto = lojas[j+1].id_produto;
                lojas[j+1].id_produto = h;
            }
        }
    }
}

int main(){
    int qntLojas;
    scanf("%d", &qntLojas);

    Loja lojas[qntLojas];

    for(int i = 0; i < qntLojas; i++){
        scanf("%d", &lojas[i].id_loja);
        scanf("%d", &lojas[i].id_produto);
    }

    printf("ARRAY PRIMÁRIO\n");
    for(int i = 0; i < qntLojas; i++){
        printf("LOJA %d COM PRODUTO %d\n", lojas[i].id_loja, lojas[i].id_produto);
    }

    BubbleSort(lojas,qntLojas);

    printf("ARRAY ORDENADO\n");
    for(int i = 0; i < qntLojas; i++){
        printf("LOJA %d COM PRODUTO %d\n", lojas[i].id_loja, lojas[i].id_produto);
    }
    return 0;
}
