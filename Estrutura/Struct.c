#include <stdio.h>
#include <stdlib.h>
#define MAX 999

typedef struct{
    char nome[MAX];
    int idade;
} Usuario;

int main(){
    
    Usuario perfil;

    scanf("%s", perfil.nome);
    scanf("%d", &perfil.idade);
    printf("IDADE: %d\n", perfil.idade);

    for(int i = 0; i < MAX; i++){
        if(perfil.nome[i] == '\0'){
            break;
        }else{
            if(i == 0){
                printf("NOME: ");
            }
            printf("%c", perfil.nome[i]);
        }
    }
    return 0;
}