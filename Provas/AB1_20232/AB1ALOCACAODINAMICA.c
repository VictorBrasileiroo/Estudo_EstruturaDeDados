#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* nome[100]; 
    int idade[100];
} Users;

void bubbleSort(Users* pessoa, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (strcmp(pessoa->nome[j], pessoa->nome[j + 1]) > 0 || 
                (strcmp(pessoa->nome[j], pessoa->nome[j + 1]) == 0 && pessoa->idade[j] > pessoa->idade[j + 1])) {
                
                char* tempNome = pessoa->nome[j];
                pessoa->nome[j] = pessoa->nome[j + 1];
                pessoa->nome[j + 1] = tempNome;

                int tempIdade = pessoa->idade[j];
                pessoa->idade[j] = pessoa->idade[j + 1];
                pessoa->idade[j + 1] = tempIdade;
            }
        }
    }
}

int main() {
    int qntUsers;
    printf("DIGITE A QUANTIDADE DE USUÁRIOS:\n");
    scanf("%d", &qntUsers);

    Users pessoa;


    for (int i = 0; i < qntUsers; i++) {
        pessoa.nome[i] = malloc(100 * sizeof(char)); 

        printf("DIGITE O NOME DO USUÁRIO:\n");
        scanf(" %s", pessoa.nome[i]); 
        getchar();

        printf("DIGITE A IDADE DO USUÁRIO:\n");
        scanf("%d", &pessoa.idade[i]);
    }

    bubbleSort(&pessoa, qntUsers);

    for (int i = 0; i < qntUsers; i++) {
        printf("O USUÁRIO %s POSSUI %d ANOS\n", pessoa.nome[i], pessoa.idade[i]);
        free(pessoa.nome[i]);
    }

    return 0;
}
