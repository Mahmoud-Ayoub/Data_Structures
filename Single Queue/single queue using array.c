/*
Author : Mahmoud Ayoub
*/

#include <stdio.h>
#include <stdlib.h>

#define max 5
int single_queue[max] ;
int front = -1 ;
int rear = -1 ;

int single_queue_is_empty (void) ;
int single_queue_is_full (void) ;
void single_enqueue (int data) ;
int single_dequeue (void) ;
void single_queue_display (void) ;

int main()
{
    int x ;

    single_enqueue(20) ;
    single_enqueue(13) ;
    single_enqueue(14) ;
    single_enqueue(15) ;
    single_enqueue(16) ;
    x = single_dequeue() ;
    printf("return value = %d \n" , x) ;
    single_queue_display() ;
    return 0;
}
int single_queue_is_empty (void) {
    if ((front == -1) && (rear == -1) )
        return 1 ;
    else
        return 0 ;
}
int single_queue_is_full (void) {
    if (rear == max - 1)
        return 1 ;
    else
        return 0 ;
}
void single_enqueue (int data) {
    if (single_queue_is_full() == 1) {
        printf("Queue is FULL \n") ;
        return ;
    }
    else{
        if (front == -1) {
            front ++ ;
        }
        rear ++ ;
        single_queue[rear] = data ;
    }

}
int single_dequeue (void) {
    if (single_queue_is_empty() == 1) {
        printf("Queue is Empty \n") ;
        return ;
    }
    else if (front == rear) {           // only one element remains in queue
        int data = single_queue[front] ;
        front = -1 ;
        rear = -1 ;
        return data ;
    }
    else {
        int data = single_queue[front] ;
        front ++ ;
        return data ;
    }

}
void single_queue_display (void) {
    if (single_queue_is_empty() == 1) {
        printf("Queue is Empty \n") ;
        return ;
    }
    else {
        int i = 0 ;
        for (i=front ; i<=rear ; i++) {
            printf("%d \n" , single_queue[i]) ;
        }
    }
}


