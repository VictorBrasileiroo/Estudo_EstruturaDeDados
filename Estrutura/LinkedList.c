#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int valor;
    struct Node *prox; 
}Node;

Node* CriarNo(int valor){
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if(novoNo == NULL) exit(1);
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void AddInicio(Node** cabeca, int valor){
    Node* novono = CriarNo(valor);
    novono->prox = *cabeca;
    *cabeca = novono;
}

void AddFim(Node** cabeca, int valor){
    Node* novono = CriarNo(valor);
    if(*cabeca == NULL){
        *cabeca = novono;
    }else{
        Node* temp = *cabeca;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = novono;
    }
}

void RemoverElemento(Node** cabeca, int valor){
    Node* temp = *cabeca;
    Node* anterior = NULL;

    if(temp != NULL && temp->valor == valor){
        *cabeca = temp->prox;
        free(temp);
        return;
    }

    while (temp != NULL && temp->valor != valor)
    {
        anterior = temp;
        temp = temp->prox;
    }

    if(temp == NULL) return;

    anterior->prox = temp->prox;
    free(temp);
}

void exibirElementos(Node** cabeca){
    Node* temp = *cabeca;
    while (temp != NULL)
    {
        printf("%d --> ", temp->valor);
        temp = temp->prox;
    }
}

void AddBegginEof(Node** head){
    int element;
    while (scanf("%d", &element) != EOF)
    {
        Node* newNode = CreateNode(element);
        newNode->prox = *head;
        *head = newNode;
    }
    
}

void inverterLista(Node** head){
    Node* atual = *head;
    Node* anterior = NULL;
    Node* proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    
}

void AddFimEof(Node **head)
{
    int element;
    while (scanf("%d", &element) != EOF)
    {
        Node *newNode = CriarNo(element);
        if (*head == NULL)
        {
            *head = newNode;
        }
        else
        {
            Node *temp = *head;
            while (temp->prox != NULL)
            {
                temp = temp->prox;
            }
            temp->prox = newNode;
        }
    }
}

int main(){
    Node* cabeca = NULL;
    AddInicio(&cabeca,8);
    AddInicio(&cabeca,5);
    AddFim(&cabeca,2);
    exibirElementos(&cabeca);
    printf("\n");
    RemoverElemento(&cabeca,8);
    exibirElementos(&cabeca);
    return 0;
}
