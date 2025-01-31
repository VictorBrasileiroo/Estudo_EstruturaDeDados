//Import das Bibliotecas usadas e Constantes
#include <stdio.h>
#include <string.h>
#define MAX 999

int ValidacaoInicioNome(char nome[], int inicio){
    return 0 ? (nome[inicio] == ' ' || nome[inicio+1] == '\0' || nome[inicio] < 'A' || nome[inicio] > 'Z') : 1;
}

int ValidacaoNome(char nome[], int inicio, int fim){  
    if(!ValidacaoInicioNome(nome, inicio)){
        return 0;
    } 
    else {
        inicio = 1;
        while(inicio <= fim){
            if(nome[inicio] == ' '){
                if(!ValidacaoInicioNome(nome, inicio + 1)){
                    return 0;
                }
            } else if((nome[inicio] < 'a' || nome[inicio] > 'z') && (nome[inicio] < 'A' || nome[inicio] > 'Z')){
                return 0;
            } else if(nome[inicio] >= 'A' && nome[inicio] <= 'Z' && nome[inicio - 1] != ' '){
                return 0;
            }
            inicio++;
        }
    }
    return 1;
}

int main(){
    char nome[MAX];
    gets(nome);
    int tam = strlen(nome);
    int resposta = ValidacaoNome(nome, 0, tam - 1);
    printf("O nome digitado é %s\n", resposta ? "válido" : "inválido");
    return 0;
}