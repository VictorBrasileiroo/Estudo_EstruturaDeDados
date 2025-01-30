#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
} Node;

Node* CreateNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) exit(1);
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

void AddToBegging(Node** head, int data){
    Node* newNode = CreateNode(data);
    newNode->next = *head;
    *head = newNode;
}

void PrintList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main(){
    Node* head = NULL;

    AddToBegging(&head,10);
    AddToBegging(&head,3);
    AddToBegging(&head,2);

    PrintList(head);
    
    return 0;
}