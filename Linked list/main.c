/*
Author : Mahmoud Ayoub
*/

#include <stdio.h>
#include <stdlib.h>

#define NULL ((void*)0)

struct node {
    int data ;
    struct node* next ;
};
struct node* head = NULL ;

struct node* newNode (void) ;
void showNode (struct node* n) ;       // function : display the linked list starting from the head
void insertNode_first (int value) ;    // function : insert new node in the first of the linked list
void insertNode_last (int value) ;     // function : insert new node in the last of the linked list
void insertNode_inbetween (int value , struct node* prev_node) ; // function : insert new node in the linked list after the given node in function

void deleteNode_first (void) ;       // function : delete node in the first of the linked list
void deleteNode_last (void) ;        // function : delete  node in the last of the linked list
void deleteNode_inbetween (struct node* prev_node) ;     // function : delete node in the linked list after the given node in function

int main()
{
    struct node* n1 = newNode() ;   // creating new node by initializing new pointer to the new node
    head = n1 ;
    n1 -> data = 10 ;

    struct node* n2 = newNode() ;
    n1 -> next = n2 ;
    n2 -> data = 5 ;
    n2 -> next = NULL ;
  
    insertNode_last(55) ;
    insertNode_first(100) ;
    insertNode_inbetween(88,n2) ;
    deleteNode_first() ;
    deleteNode_inbetween(n1) ;
    deleteNode_last() ;
    showNode(head) ;                        /*  Output : value of node = 10
                                                         value of node = 88    */

    return 0;
}
struct node* newNode (void) {
    struct node* p = (struct node*) malloc(sizeof(struct node)) ;
    return p ;

}

void showNode (struct node* h) {
    struct node* ptr = h ;
    while (ptr != NULL) {
            printf("value of node = %d \n" , ptr->data) ;
            ptr = ptr->next ;
    }
}

void insertNode_first (int value) {
    struct node* new_ptr = newNode() ;
    new_ptr -> data = value ;
    new_ptr -> next = head ;
    head = new_ptr ;

}
void insertNode_last (int value) {
    struct node* last_ptr = newNode() ;
    struct node* h = head ;
    last_ptr -> data = value ;
    last_ptr -> next = NULL ;
    while (h->next != NULL) {    // search for the node which its next pointer = NULL (last node before insertion)
       h = h->next ;
    }
    h -> next = last_ptr ;

}

void insertNode_inbetween (int value , struct node* prev_node) {
    struct node* inbetween = newNode() ;
    inbetween -> data = value ;
    inbetween -> next = prev_node -> next ;
    prev_node -> next = inbetween ;
}

void deleteNode_first (void) {
    struct node* h = head ;
    head = h -> next ;
    free(h) ;
}

void deleteNode_last (void) {
    struct node* ptr = head ;
    struct node* n;
    while (ptr->next != NULL) {
        n = ptr ;
        ptr = ptr -> next ;
    }
    n -> next = NULL ;
    free(ptr) ;
}

void deleteNode_inbetween (struct node* prev_node) {
    struct node* p = prev_node -> next ;
    prev_node -> next = p -> next ;
    free(p) ;
}
