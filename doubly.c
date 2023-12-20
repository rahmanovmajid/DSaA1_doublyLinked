#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Node* newNode(int data);
void insertAtBeginning(int data,struct Node** new_node);
void insertAtEnding();
void insertAfter();
void insertBefore();
void printList(struct Node** firstnode);

int main(){

    struct Node* mynode = newNode(1);
    printList(&mynode);






    return 0;
}

struct Node* newNode(int data){
    struct Node *ptr;
    ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->value;
    ptr->prev = NULL;
    ptr->next = NULL; 
    return ptr;
}

void insertAtBeginning(int data,struct Node** current_node){
    struct Node *new_node = newNode(data);
    new_node->next = *current_node;
    (*current_node)->prev = new_node;
    *current_node = new_node;
}

void insertAtEnding(int data,struct Node** current_node){
    struct Node *new_node = newNode(data);
    (*current_node)->next = new_node;
    new_node->prev = *current_node;
    *current_node = new_node;
}

void insertAfter(int data,struct Node** current_node){
    struct Node *new_node = newNode(data);
    new_node->next = (*current_node)->next;
    new_node->prev = (*current_node)->next->prev;
    (*current_node)->next->prev = new_node;
    (*current_node)->next = new_node;

    // new_node->prev = *current_node;
    // new_node->next = (*current_node)->next;
    // (*current_node)->next = new_node;
    // *current_node = new_node;
}           


void insertBefore(int data,struct Node** current_node){
    struct Node *new_node = newNode(data);
    new_node->prev = (*current_node)->prev;
    new_node->next = (*current_node)->prev->next;
    (*current_node)->prev->next = new_node;
    (*current_node)->prev = new_node;
}


void printList(struct Node** firstnode){
    while( (*firstnode) != NULL ){
        printf("%d, ",(*firstnode)->value);
        (*firstnode) = (*firstnode)->next;
    }
}


