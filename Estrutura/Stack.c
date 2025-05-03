#include <stdio.h>
#include <stdlib.h>

// topo -> posição onde um novo elemento entrará
// empilhar -> novo elemento -> incrementa topo
// desempilhar -> Pop elemento -> decrementa topo
// stack overflow -> topo = null
// stack empty -> topo = 0


//TOPO É O INICIO (CABECA DA LISTA) --> INSERÇÃO NO INICIO -> O(1)

typedef struct Node {
    int value;
    struct Node* prox;
} Node;

typedef struct Stack {
    Node* topo;
} Stack;

void inicializa(Stack* p) {
    p->topo = NULL;
}

int estaVazia(Stack* p){
    return (p->topo == NULL);
}

// p->topo
//    ↓
//  [ A ] → [ B ] → NULL

//INSERIR C

// p->topo
//    ↓
//  [ C ] → [ A ] → [ B ] → NULL

void Push(Stack* p, int element){
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if(novoNo){
        novoNo->value = element;
        novoNo->prox = p->topo;
        p->topo = novoNo;
    }
}

int Pop(Stack* p){
    Node* t = p->topo;
    int x = p->topo->value;
    p->topo = t->prox;
    free(t);
    return x;
}

void Desempilhar(Stack* p){
    while (p->topo != NULL) Pop(p);
}

void exibirPilha(Stack* p){
    Node* t = p->topo;
    while (t != NULL)
    {
        printf("%d ->", t->value);
        t = t->prox;
    }
    printf("NULL\n"); // Add newline and indicate end of stack
}

int main() {
    Stack p;
    inicializa(&p); 
    Push(&p,10);
    Push(&p,20);
    Push(&p,30);
    exibirPilha(&p);
    Pop(&p);
    Pop(&p);
    exibirPilha(&p);
    return 0;
}