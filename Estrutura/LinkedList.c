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

void addFim(Node** head, int element){
    Node* novoNo = CriarNo(element);
    if(head == NULL){
        *head = novoNo;
    }else{
        Node* temp = head;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = novoNo;
    } 
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

void inserirLocal(Node** head, int element, int pos){
    Node* novoNo = CriarNo(element);
    if(*head == NULL || pos == 0){
        novoNo->prox = *head;
        *head = novoNo;
        return;
    }
    
        Node* t = *head;
        int i = 0;

        while (i < pos - 1 && t != NULL)
        {
           t = t->prox;
           i++;
        }

        novoNo->prox = t->prox;
        t->prox = novoNo;
}

void Buscar(Node* head, int element){
    while (head != NULL)
    {
        if(head->valor == element){
            return 1;
        }
        head = head->prox;
    }
    return 0;
}

int Tamanho(Node* head){
    int i = 0;
    while (head != NULL)
    {
        head = head->prox;
        i++;
    }
    return i;
}

int main() {
    return 0;
}
