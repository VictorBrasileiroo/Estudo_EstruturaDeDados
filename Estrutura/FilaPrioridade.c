#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int prioridade;
    struct Node* prox;
} Node;

typedef struct {
    Node* front;
} Queue;

void inicializar(Queue* f) {
    f->front = NULL;
}

void Push(Queue* f, int valor, int prioridade) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->value = valor;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    if (f->front == NULL || prioridade < f->front->prioridade) {
        novo->prox = f->front;
        f->front = novo;
    } else {
        Node* t = f->front;
        while (t->prox != NULL && t->prox->prioridade <= prioridade) {
            t = t->prox;
        }
        novo->prox = t->prox;
        t->prox = novo;
    }
}

void exibirFila(Queue* f) {
    Node* t = f->front;
    while (t != NULL) {
        printf("%d (p:%d) -> ", t->value, t->prioridade);
        t = t->prox;
    }
    printf("NULL\n");
}

int pop(Queue* f){
    if(f->front == NULL) return -1;
    Node* t = f->front;
    int valor = t->value;
    f->front = f->front->prox;
    free(t);
    return valor;
}

int main() {
    Queue fila;
    inicializar(&fila);

    Push(&fila, 100, 2);
    Push(&fila, 200, 5);
    Push(&fila, 300, 1);
    Push(&fila, 150, 3);
    pop(&fila);
    exibirFila(&fila);

    return 0;
}
