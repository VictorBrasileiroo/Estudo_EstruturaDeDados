#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int codigo;
    char descricao[100];
    char marca[50];
    Data validade;
    int quantidade;
}Produto;

typedef struct{
    Produto Info;
    struct Node* prox;
}Node;


Produto CadastrarProduto(){
    Produto newProduct;
    scanf("%d", &newProduct.codigo);
    scanf("%d", &newProduct.quantidade);
    scanf("%d", &newProduct.validade.ano);
    scanf("%d", &newProduct.validade.mes);
    scanf("%d", &newProduct.validade.dia);

    getchar();

    fgets(newProduct.descricao, 100,stdin);
    fgets(newProduct.marca, 50,stdin);

    return newProduct;
}

Node* CriarNo() {
 Node* novoProduto = (Node*)malloc(sizeof(Node));
 novoProduto->Info = CadastrarProduto();
 novoProduto->prox = NULL;
 return novoProduto;
}

void addFim(Node** head){
    Node* novoNo = CriarNo();
    if(*head == NULL){
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

void Print(Node* lista) {
    printf("\n--------------- ESTOQUE ---------------\n");

    while (lista != NULL) {
        printf("| %d | %s | %s | %02d/%02d/%04d | %d |\n",
               lista->Info.codigo,
               lista->Info.descricao,
               lista->Info.marca,
               lista->Info.validade.dia,
               lista->Info.validade.mes,
               lista->Info.validade.ano,
               lista->Info.quantidade);

        lista = lista->prox;
    }

    printf("------------- FIM ESTOQUE --------------\n");
}

int main(){
    Node* head = NULL;
    addFim(&head);
    Print(head);
    return 0;
}