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

int circular_queue_is_empty (void) ;       // NOTE : there is NO is_full function as it is dynamic memory allocation
void circular_enqueue (int value) ;         // Add last in linked list
int circular_dequeue (void) ;               // Delete first in linked list
void circular_queue_display (void) ;


int main()
{
    circular_enqueue(5) ;
    circular_enqueue(10) ;
    circular_enqueue(15) ;
    circular_enqueue(20) ;
    circular_enqueue(25) ;
    circular_dequeue() ;
    circular_enqueue(22) ;


    circular_queue_display() ;


    return 0;
}

int circular_queue_is_empty (void) {
    if (front == NULL)
        return 1 ;
    else
        return 0 ;
}
void circular_enqueue (int value) {
    if (circular_queue_is_empty() == 1) {     // queue is empty
        rear = (node*) malloc(sizeof(node)) ;
        front = rear ;
        rear -> data = value ;
        rear -> next = front ;               /* NOTE : it doesn't point to NULL , it must point to itself */
    }
    else {
        rear -> next = (node*) malloc(sizeof(node)) ;
        rear = rear -> next ;                       /* TRICK : add last in linked list without need to temp */
        rear -> data = value ;
        rear -> next = front ;                      /* NOTE : it doesn't point to NULL , it must point to itself */
    }
}
int circular_dequeue (void) {
    if (circular_queue_is_empty() == 1) {
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
void circular_queue_display (void) {
    if (circular_queue_is_empty() == 1) {
        return ;
    }
    else {
        node* temp = front ;
        do {
            printf("%d \n" , temp->data) ;
            temp = temp -> next ;
        }
        while (temp !=front) ;             /* NOTE : it doesn't point to NULL , it must point to itself */

    }
}
