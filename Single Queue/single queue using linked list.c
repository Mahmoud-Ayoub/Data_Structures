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
node* front = NULL ;
node* rear = NULL ;

int single_queue_is_empty (void) ;       // NOTE : there is NO is_full function as it is dynamic memory allocation
void single_enqueue (int value) ;         // Add last in linked list
int single_dequeue (void) ;               // Delete first in linked list
void single_queue_display (void) ;


int main()
{
    single_enqueue(12) ;
    single_enqueue(13) ;
    single_enqueue (14) ;
    single_queue_display() ;

    return 0;
}

int single_queue_is_empty (void) {
    if (front == NULL)
        return 1 ;
    else
        return 0 ;
}
void single_enqueue (int value) {
    if (single_queue_is_empty() == 1) {     // queue is empty
        rear = (node*) malloc(sizeof(node)) ;
        front = rear ;
        rear -> data = value ;
        rear -> next = NULL ;
    }
    else {
        rear -> next = (node*) malloc(sizeof(node)) ;
        rear = rear -> next ;                       // TRICK : add last in linked list without need to temp
        rear -> data = value ;
        rear -> next = NULL ;
    }
}
int single_dequeue (void) {
    if (single_queue_is_empty() == 1) {
        printf("Queue is Empty \n") ;
        return -1 ;
    }
    else if (rear == front) {          // we have only one node in queue
        int data = front -> data ;
        free(front) ;
        front = NULL ;
        rear = NULL ;
        return data ;
    }
    else {                           // we have more than one node in queue
        node* temp = front ;
        int data = temp -> data ;
        front = temp -> next ;
        free(temp) ;
        return data ;
    }
}
void single_queue_display (void) {
    if (single_queue_is_empty() == 1) {
        return ;
    }
    else {
        node* temp = front ;
        while (temp != NULL) {
            printf("%d \n" , temp->data) ;
            temp = temp -> next ;
        }
    }
}
