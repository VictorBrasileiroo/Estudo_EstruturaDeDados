#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valor;
    struct node* prox;
} Node;

// Cria um novo nó com valor
Node* CriarNo(int element) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->valor = element;
    novo->prox = NULL;
    return novo;
}

// Insere um elemento no início da lista
void AddInicio(Node** head, int element) {
    Node* novo = CriarNo(element);
    novo->prox = *head;
    *head = novo;
}

// Exibe os elementos da lista
void ExibirElementos(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }
    printf("NULL\n");
}

// Inverte a lista ligada
void InverterLista(Node** head) {
    Node* anterior = NULL;
    Node* atual = *head;
    Node* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *head = anterior;
}

// Concatena duas listas e retorna a nova cabeça
Node* ConcatenarListas(Node* cabeca1, Node* cabeca2) {
    if (cabeca1 == NULL) return cabeca2;

    Node* temp = cabeca1;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = cabeca2;
    return cabeca1;
}


// Libera memória da lista
void LiberarLista(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->prox;
        free(temp);
    }
}

int main() {
    Node* cabeca1 = NULL;
    Node* cabeca2 = NULL;

    // Exemplo de preenchimento
    AddInicio(&cabeca1, 1);
    AddInicio(&cabeca1, 3);
    AddInicio(&cabeca1, 2);
    AddInicio(&cabeca1, 0);
    AddInicio(&cabeca1, 4);

    AddInicio(&cabeca2, 1);
    AddInicio(&cabeca2, 5);
    AddInicio(&cabeca2, 7);

    printf("Lista 1:\n");
    ExibirElementos(cabeca1);

    printf("\nLista 2:\n");
    ExibirElementos(cabeca2);

    // Concatena as listas
    Node* cabeca3 = ConcatenarListas(cabeca1, cabeca2);
    printf("\nLista concatenada:\n");
    ExibirElementos(cabeca3);
    return 0;
}
