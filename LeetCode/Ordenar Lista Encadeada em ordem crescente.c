#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int valor;
    struct Node *prox;
} Node;

Node *CriarNo(int valor)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    if (novoNo == NULL)
        exit(1);
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void exibirElementos(Node **cabeca)
{
    Node *temp = *cabeca;
    while (temp != NULL)
    {
        printf("%d ", temp->valor);
        temp = temp->prox;
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

void inverterLista(Node **head)
{
    Node *atual = *head;
    Node *anterior = NULL;
    Node *proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *head = anterior;
}

int main()
{
    Node *cabeca = NULL;
    AddFimEof(&cabeca);
    inverterLista(&cabeca);
    exibirElementos(&cabeca);
    return 0;
}
