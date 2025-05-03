#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* prox;
} Node;

typedef struct{
    Node* front;
    Node* back;
} Queue;

void incializarFila(Queue* f){
    f->back = NULL;
    f->front = NULL;
}

//frente e tras são invertidos 

// [10] -> [20] -> [30] -> NULL
//  ^                     ^
// frente               tras


void push(Queue* f, int value){
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->value = value;
    novoNo->prox = NULL;

    if(f->back == NULL){
        f->front = novoNo;
        f->back = novoNo;
    }else{
        f->back->prox = novoNo; //o antigo final agora aponta para o novo no
        f->back = novoNo; //o final da fila agora vira o novo no

        // [10] -> [20] -> NULL
                //   ^
                //  back

        // [10] -> [20] -> [30] -> NULL
        //                  ^
        //                 back
    }
}

int pop(Queue* f){
    if(f->front == NULL) return -1;
    Node* t = f->front;
    int valor = t->value;
    f->front = f->front->prox;

    if(f->front == NULL){
        f->back == NULL;
    }
    free(t);
    return valor;
}

void exibirFila(Queue* f){
    Node* t = f->front;
    while (t != NULL)
    {
        printf("%d -> ", t->value);
        t = t->prox;
    }
    printf("\n");
}

int main(){
    Queue f;
    incializarFila(&f);
    push(&f, 10);
    push(&f, 20);
    push(&f, 30);
    exibirFila(&f);
    pop(&f);
    pop(&f);
    exibirFila(&f);
    return 0;
}