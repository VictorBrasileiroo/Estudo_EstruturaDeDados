//Faça um **SORT***** para ordenar de forma crescente** um vetor estático em **C** cuja informação é do tipo definido abaixo. Este programa deverá ler as entradas e imprimir o vetor de entrada, seguido do vetor com os mesmos dados de entrada, só que ordenados.


//OBSERVAÇÕES!!!!!!!!!!!!!!!!!!!!!
//QUANDO PASSAR UM STRUCT COMO REFERENCIA PARA UMA FUNÇÃO USE PONTEIROS!! TANTO NO PARÂMETRO QUANTO NO -> DAS OPERAÇÕES E & NA CHAMADA

#include <stdio.h>

typedef struct {
    int id_loja[100];
    int id_produto[100];
}Loja;

void cadastrarLojas(Loja *lojas, int qntLojas){
    //excessões --> n pode ter lojas com ids maiores que 100 e produtos maiores que 50  
    for(int i = 0; i < qntLojas; i++){
        printf("DIGITE O ID DA SUA LOJA \n");
        scanf("%d", &lojas->id_loja[i]);
        if(lojas->id_loja[i] > 100){
            printf("ID INVÁLIDO!");
            break;
        }
        printf("DIGITE O ID DO PRODUTO ASSOCIADO A LOJA %d \n", lojas->id_loja[i]);
        scanf("%d", &lojas->id_produto[i]);
        if(lojas->id_produto[i] > 50){
            printf("ID INVÁLIDO!");
            break;
        }
    }
}

void bubbleSort(Loja *lojas, int tam){
    // IMPORTANTEEEEEEEEEEEEEEEEEE --->>>>>>>>>>>> SE EU TROQUEI OS IDS DA LOJA DE LUGAR EU PRECISO FAZER A TROCA DO ID DO PRODUTO TAMBÉM DE LUGAR --> SENAO EMABARA AS PARADAS
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

    printf("QUANTAS LOJAS O SENHOR DESEJA CADASTRAR? \n");
    int qntLojas;
    scanf("%d", &qntLojas);

    cadastrarLojas(&lojas, qntLojas);   
    
    printf("LOJAS INICIAIS:\n");
    printLojas(&lojas,qntLojas);

    bubbleSort(&lojas,qntLojas);
    printf("\n");

    printf("LOJAS ORDENADAS:\n");
    printLojas(&lojas,qntLojas);
    return 0;
}