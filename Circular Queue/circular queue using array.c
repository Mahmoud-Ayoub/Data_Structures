/*
Author : Mahmoud Ayoub
*/

#include <stdio.h>
#include <stdlib.h>

#define max 5
int circular_queue[max] ;
int front = -1 ;
int rear = -1 ;

int circular_queue_is_full (void) ;
int circular_queue_is_empty (void) ;
void circular_enqueue (int data) ;
int circular_dequeue (void) ;
void circular_queue_display (void) ;

int main()
{
    circular_enqueue(5) ;
    circular_enqueue(6) ;
    circular_enqueue(7) ;
    circular_enqueue(8) ;
    circular_enqueue(9) ;
    circular_dequeue() ;
    circular_enqueue(22) ;


    circular_queue_display() ;


    return 0;
}
int circular_queue_is_full (void) {
    if ((rear+1) % max == front)          // OR another simple condition
        return 1 ;                        /* if ( (front == 0 && rear == max - 1) || (rear == front - 1) )  */
    else
        return 0 ;
}
int circular_queue_is_empty (void) {
    if ((front == -1) && (rear == -1))
        return 1 ;
    else
        return 0 ;
}
void circular_enqueue (int data) {
    if (circular_queue_is_full() == 1) {
        printf("Circular Queue is Full \n") ;
        return ;
    }
    else if (front == -1) {           // First element in the circular queue
        front ++ ;
        rear ++ ;
        circular_queue[rear] = data ;
    }
    else {
                                    // to enter forward data and also enter data circular if the queue is empty at the beginning
        rear = (++rear % max) ;
        circular_queue[rear] = data ;
    }
}
int circular_dequeue (void) {
    if (circular_queue_is_empty() == 1) {
        printf("Circular Queue is Empty \n") ;
        return ;
    }
    else if (front == rear) {           // only one element in the queue
        int value = circular_queue[front] ;
        front = -1 ;
        rear = -1 ;
        return value ;
    }
    else {
        int value = circular_queue[front] ;
        front ++ ;
        if (front == max)
            front = 0 ;
        return value ;
    }
}
void circular_queue_display (void) {
    if (circular_queue_is_empty() == 1) {
        printf("Circular Queue is Empty \n") ;
        return ;
    }
    else if (front < rear) {
        int i = 0 ;
        for (i=front ; i<=rear ; i++){
            printf("%d \n" , circular_queue[i]) ;
        }
    }
    else {
        int i = 0 ;
        for (i=front ; i <= max-1 ; i++) {
            printf("%d \n" , circular_queue[i]) ;
        }
        front = 0 ;
        for (i=front ; i<=rear ; i++) {
            printf("%d \n" , circular_queue[i]) ;

        }
    }
}

