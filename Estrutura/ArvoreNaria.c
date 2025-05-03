#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* primeiroFilho;
    struct No* proximoIrmao;
} No;

No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->primeiroFilho = NULL;
    novo->proximoIrmao = NULL;
    return novo;
}

void adicionarFilho(No* pai, No* filho) {
    if (pai->primeiroFilho == NULL) {
        pai->primeiroFilho = filho;
    } else {
        No* atual = pai->primeiroFilho;
        while (atual->proximoIrmao != NULL) {
            atual = atual->proximoIrmao;
        }
        atual->proximoIrmao = filho;
    }
}

void imprimirArvore(No* raiz, int nivel) {
    if (raiz == NULL) return;
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("%d\n", raiz->valor);
    imprimirArvore(raiz->primeiroFilho, nivel + 1);
    imprimirArvore(raiz->proximoIrmao, nivel);
}

No* somarArvores(No* a, No* b) {
    if (a == NULL && b == NULL) return NULL;

    No* novo = (No*) malloc(sizeof(No));
    novo->valor = (a ? a->valor : 0) + (b ? b->valor : 0);
    novo->primeiroFilho = NULL;
    novo->proximoIrmao = NULL;

    No* filhoA = a ? a->primeiroFilho : NULL;
    No* filhoB = b ? b->primeiroFilho : NULL;

    No* ultimoFilho = NULL;
    while (filhoA != NULL || filhoB != NULL) {
        No* filhoSomado = somarArvores(filhoA, filhoB);

        if (ultimoFilho == NULL) {
            novo->primeiroFilho = filhoSomado;
        } else {
            ultimoFilho->proximoIrmao = filhoSomado;
        }

        ultimoFilho = filhoSomado;

        if (filhoA) filhoA = filhoA->proximoIrmao;
        if (filhoB) filhoB = filhoB->proximoIrmao;
    }

    return novo;
}

int main() {
    // Árvore 1
    No* a1 = criarNo(2);
    No* a1_f1 = criarNo(3);
    No* a1_f2 = criarNo(4);
    adicionarFilho(a1, a1_f1);
    adicionarFilho(a1, a1_f2);

    // Árvore 2
    No* a2 = criarNo(1);
    No* a2_f1 = criarNo(5);
    adicionarFilho(a2, a2_f1);

    printf("Árvore 1:\n");
    imprimirArvore(a1, 0);

    printf("\nÁrvore 2:\n");
    imprimirArvore(a2, 0);

    No* resultado = somarArvores(a1, a2);
    printf("\nSoma das Árvores:\n");
    imprimirArvore(resultado, 0);

    return 0;
}
