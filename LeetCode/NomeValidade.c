// INTEGRANTES DO GRUPO DE ESTRUTURA DE DADOS 2024.2
// 1. VICTOR ANDRÉ LOPES BRASILEIRO
// 2. ERASMO DA SILVA SÁ JUNIOR
// 3. ARTUR FERREIRA MARQUES DA SILVA
// 4. MARIO DIEGO FERREIRA DOS SANTOS
// 5. CAIO HENRIQUE GAVAZZA PATRIOTA

#include <stdio.h>
#include <string.h>
#define MAX 999

int ValidacaoInicioNome(char nome[], int inicio) {
    return (nome[inicio] == ' ' || nome[inicio+1] == '\0' || nome[inicio] < 'A' || nome[inicio] > 'Z') ? 0 : 1;
}

int ValidacaoNome(char nome[], int inicio, int fim) {  
    if (!ValidacaoInicioNome(nome, inicio)) {
        return 0;
    } else {
        inicio = 1;
        while (inicio <= fim) {
            if (nome[inicio] == ' ') {
                if (!ValidacaoInicioNome(nome, inicio + 1)) {
                    return 0;
            }
            } else if ((nome[inicio] < 'a' || nome[inicio] > 'z') && (nome[inicio] < 'A' || nome[inicio] > 'Z')) {
                return 0;
            } else if (nome[inicio] >= 'A' && nome[inicio] <= 'Z' && nome[inicio - 1] != ' ') {
                return 0;
            }
            inicio++;
        }
    }
    return 1;
}

int main() {
    char nome[MAX];
    gets(nome);
    int tam = strlen(nome);
    int resposta = ValidacaoNome(nome, 0, tam - 1);
    printf("O nome digitado é %s\n", resposta ? "válido" : "inválido");
    return 0;
}
