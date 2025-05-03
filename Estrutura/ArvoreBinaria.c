#include <stdio.h>
#include <stdlib.h>

typedef struct NodeTree{
    int value;
    struct NodeTree* esquerda;
    struct NodeTree* direita;
}NodeTree;

NodeTree* criarNode(int valor){
    NodeTree* novoNo = (NodeTree*)malloc(sizeof(NodeTree));
    novoNo->value = valor;
    novoNo->direita = NULL;
    novoNo->esquerda = NULL;
    return novoNo;
}


//vai percorrendo direita e esquerada ate achar um null e preencher
NodeTree* inserir(int valor, NodeTree* raiz){
    if(raiz == NULL) return criarNode(valor);
    if(valor < raiz->value){
        raiz->esquerda = inserir(valor, raiz->esquerda);
    }else{
        raiz->direita = inserir(valor, raiz->direita);
    }
    return raiz;
}

void Exibir(NodeTree* raiz){
    if(raiz != NULL){
        Exibir(raiz->esquerda);
        printf("%d ", raiz->value);
        Exibir(raiz->direita);
    }
}

int main(){
    NodeTree* raiz = NULL;
    raiz = inserir(10, raiz);
    raiz = inserir(20, raiz);
    raiz = inserir(30, raiz);
    Exibir(raiz);
    return 0;
}