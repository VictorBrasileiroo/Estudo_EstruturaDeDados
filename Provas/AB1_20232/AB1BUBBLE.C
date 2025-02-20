#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[250][100]; 
    int idade[100];
} Users;

void bubbleSort(Users* pessoa, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam - 1 - i; j++){
            if((strcmp(pessoa->nome[j], pessoa->nome[j+1]) > 0) || (strcmp(pessoa->nome[j], pessoa->nome[j+1]) == 0 && (pessoa->idade[j] > pessoa->idade[j+1]))){
                for (int k = 0; k < 100; k++) {
                    char temp = pessoa->nome[j][k];
                    pessoa->nome[j][k] = pessoa->nome[j+1][k];
                    pessoa->nome[j+1][k] = temp;
                    if (pessoa->nome[j][k] == '\0' && pessoa->nome[j+1][k] == '\0') {
                        break;
                    }
                }

                int tempIdade = pessoa->idade[j];
                pessoa->idade[j] = pessoa->idade[j+1];
                pessoa->idade[j+1] = tempIdade;
            }
        }
    }
}

int main() {
    int qntUsers;
    
    printf("DIGITE A QUANTIDADE DE USUÁRIOS:\n");
    scanf("%d", &qntUsers); 
    getchar();

    Users pessoa;

    for (int i = 0; i < qntUsers; i++) {
        printf("DIGITE O NOME DO USUÁRIO:\n");
        fgets(pessoa.nome[i], 100, stdin);
        pessoa.nome[i][strcspn(pessoa.nome[i], "\n")] = '\0';

        printf("DIGITE A IDADE DO USUÁRIO:\n");
        scanf("%d", &pessoa.idade[i]);
        getchar();
    }

    bubbleSort(&pessoa,qntUsers);

    for (int i = 0; i < qntUsers; i++) {
        printf("O USUÁRIO %s POSSUI %d ANOS\n", pessoa.nome[i], pessoa.idade[i]);
    }

    return 0;
}