#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next; 
};

struct Node* CreateNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    /*
        1. malloc(sizeof(struct Node)) aloca um bloco de memória no heap do tamanho de struct Node.
        2. Esse bloco de memória não tem valores definidos (conteúdo indefinido até que seja inicializado).
        3. O endereço desse bloco de memória é retornado pelo malloc.
        4. (struct Node*) faz o typecast para um ponteiro do tipo struct Node*, pois malloc retorna void*.
        5. O ponteiro newNode agora armazena o endereço da memória recém-alocada.
    */

    //Verifica se o novo nó tem memória alocada
    if(newNode == NULL){
        printf("Não foi possível alocar memória!\n");
        exit(1);
    }
    
    newNode->data = data; //basicamente seria algo assim --> newNode.data = data(da função).
    newNode->next = NULL; // O próximo ainda não existe, então null.

    return newNode;
}

struct Node* InsertNodeAtBeginning(struct Node** head, int data){
    struct Node* newNode = CreateNode(data); //cria o novo nó

    newNode->next = *head; //faz o novo nó apontar para o antigo primeiro nó --> ou seja ele vira o primeiro

    *head = newNode; // faz o ponteiro do inicio ser o novo nó

    // 1. head -> [1, next] -> [10, null] // assim era no inicio
    //2 . [10,null] // criamos o nó sem ponteiro para o próximo
    //3. head -> [10, next] -> [1,next] -> [10, null] // aqui dizemos que o ponteiro para o próximo é igual ao ponteiro head --> ou seja, ele agora aponta para o nó que o head apontava --> e o head agora aponta para o endereço de memória do novo nó
}

// Função para inserir um nó no final da lista encadeada
struct Node* InsertNodeAtEnd(struct Node** head, int data) {
    // Cria um novo nó e atribui o valor 'data' a ele
    struct Node* newNode = CreateNode(data); 

    // Se a lista estiver vazia (*head == NULL), o novo nó se torna o primeiro nó
    if (*head == NULL) {
        *head = newNode;  // Agora a cabeça da lista aponta para o novo nó
        return;  // Retorna, pois já inserimos o nó e não precisamos percorrer a lista
    }

    // Cria um ponteiro temporário para percorrer a lista, começando pelo primeiro nó
    struct Node* temp = *head;

    // Percorre a lista até encontrar o último nó (onde temp->next é NULL)
    while (temp->next != NULL) {
        temp = temp->next; // Move para o próximo nó da lista
    }

    // Ao chegar no último nó (temp->next == NULL), faz ele apontar para o novo nó
    temp->next = newNode;
}

void PrintList(struct Node* head){
    struct Node* temp = head;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL \n");
}

int main(){
    struct Node* head = NULL; //cria uma lista vazia --> pois quando head aponta para nada quer dizer que a lista ta vazia

    InsertNodeAtBeginning(&head, 10);
    InsertNodeAtBeginning(&head, 2);
    InsertNodeAtBeginning(&head, 3);
    InsertNodeAtEnd(&head, 5);

    PrintList(head);

    return 0;
}