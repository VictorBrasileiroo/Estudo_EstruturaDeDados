// INTEGRANTES DO GRUPO DE ESTRUTURA DE DADOS 2024.2
// 1. VICTOR ANDRÉ LOPES BRASILEIRO
// 2. ERASMO DA SILVA SÁ JUNIOR
// 3. ARTUR FERREIRA MARQUES DA SILVA
// 4. MARIO DIEGO FERREIRA DOS SANTOS
// 5. CAIO HENRIQUE GAVAZZA PATRIOTA

// Importação das bibliotecas necessárias e definição de constantes
#include <stdio.h>
#include <string.h>
#define MAX 999  // Define o tamanho máximo do nome

// Função para validar as condições iniciais de um nome:
// - A primeira letra não pode ser minúscula.
// - O nome não pode estar vazio.
// - O nome não pode conter apenas uma letra.
// Esta função é chamada no início de cada palavra (após um espaço ou no início do nome).
int ValidacaoInicioNome(char nome[], int inicio) {
    // Retorna 0 se as condições não forem atendidas, caso contrário retorna 1
    return (nome[inicio] == ' ' || nome[inicio+1] == '\0' || nome[inicio] < 'A' || nome[inicio] > 'Z') ? 0 : 1;
}

// Função principal para validar o nome completo:
// - Verifica se todas as palavras começam com letra maiúscula.
// - Verifica se os caracteres são letras válidas (maiúsculas ou minúsculas).
// - Verifica se as letras maiúsculas só aparecem no início de palavras.
int ValidacaoNome(char nome[], int inicio, int fim) {  
    // Valida a primeira letra do nome
    if (!ValidacaoInicioNome(nome, inicio)) {
        return 0;  // Retorna 0 se a primeira letra for inválida
    } else {
        // Percorre o nome a partir da segunda letra
        inicio = 1;
        while (inicio <= fim) {
            // CASO 1: Se encontrar um espaço, a próxima letra deve ser maiúscula
            if (nome[inicio] == ' ') {
                if (!ValidacaoInicioNome(nome, inicio + 1)) {
                    return 0;  // Retorna 0 se a próxima letra após o espaço for inválida
                }
            // CASO 2: Se o caractere não for uma letra (maiúscula ou minúscula), é inválido
            } else if ((nome[inicio] < 'a' || nome[inicio] > 'z') && (nome[inicio] < 'A' || nome[inicio] > 'Z')) {
                return 0;  // Retorna 0 se o caractere não for uma letra
            // CASO 3: Se encontrar uma letra maiúscula que não esteja no início de uma palavra, é inválido
            } else if (nome[inicio] >= 'A' && nome[inicio] <= 'Z' && nome[inicio - 1] != ' ') {
                return 0;  // Retorna 0 se a letra maiúscula não estiver no lugar correto
            }
            inicio++;  // Avança para o próximo caractere
        }
    }
    return 1;  // Retorna 1 se o nome for válido
}

// Função principal
int main() {
    char nome[MAX];  // Declara um array para armazenar o nome
    gets(nome);  // Lê o nome digitado pelo usuário (não recomendado para uso em produção)
    int tam = strlen(nome);  // Calcula o tamanho do nome
    int resposta = ValidacaoNome(nome, 0, tam - 1);  // Valida o nome
    printf("O nome digitado é %s\n", resposta ? "válido" : "inválido");  // Exibe o resultado
    return 0;
}