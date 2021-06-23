/*
Author : Mahmoud Ayoub
*/

#include <stdio.h>
#include <stdlib.h>

#define NULL ((void*)0)

typedef struct node {
    int data ;
    struct node* next ;
}node;
node* top = NULL ;          // NOTE : top here is pointer not index

node* newNode (void) ;
void insertNode_first (int value) ;    // function : insert new node in the first of the linked list
int deleteNode_first (void) ;       // function : delete node in the first of the linked list
void showNode (struct node* n) ;       // function : display the linked list starting from the head
int Stack_is_empty (void) ;          // NOTE : there is NO is_full function as it is dynamic memory allocation
void Stack_push (int value) ;
int Stack_pop (void) ;
void Stack_display (void) ;



int main()
{
    Stack_push(10) ;
    Stack_push(100) ;
    Stack_push(200) ;
    Stack_display() ;
    return 0;
}
struct node* newNode (void) {
    node* p = (node*) malloc(sizeof(node)) ;
    return p ;
}
void insertNode_first (int value) {
    node* new_ptr = newNode() ;
    new_ptr -> data = value ;
    new_ptr -> next = top ;
    top = new_ptr ;
}
int deleteNode_first (void) {
    node* temp = top ;
    top = temp -> next ;
    int data = temp -> data ;          // to save data of the deleted node (not just delete it)
    free(temp) ;
    return data ;
}
void showNode (struct node* n) {
    node* ptr = n ;
    while (ptr != NULL){
        printf("%d \n" , ptr->data) ;
        ptr = ptr -> next ;
    }
}
int Stack_is_empty (void) {
    if (top == NULL)
        return 1 ;
    else
        return 0 ;
}
void Stack_push (int value) {
    insertNode_first(value) ;
}
int Stack_pop (void) {
    int data ;
    if (Stack_is_empty() == 1) {
        printf("Empty stack \n") ;
        return ;
    }
    else {
        data = deleteNode_first() ;
        return data ;
    }
}
void Stack_display (void) {
    if (Stack_is_empty() == 1) {
        printf("Empty Stack \n") ;
        return ;
    }
    else {
         node* temp = top ;
         showNode(temp) ;
    }
}
