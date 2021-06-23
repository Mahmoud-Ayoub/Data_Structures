/*
Author : Mahmoud Ayoub
*/
#include <stdio.h>
#include <stdlib.h>

#define max 5
int Stack [max] ;
int top = -1 ;          // NOTE : top is an index not pointer

int Stack_is_empty (void) ;
int Stack_is_full (void) ;
void Stack_push (int value) ;
int Stack_pop (void) ;
void Stack_display (void) ;

int main()
{
    Stack_push(100) ;
    Stack_push(200) ;
    Stack_push(300) ;
    Stack_push(40) ;
    Stack_pop();
    Stack_display() ;               

    return 0;
}
int Stack_is_empty (void) {
    if (top == -1)
        return 1 ;
    else
        return 0 ;
}
int Stack_is_full (void) {
    if (top == max-1)
        return 1 ;
    else
        return 0 ;
}
void Stack_push (int value) {
    if (Stack_is_full() == 1) {        // before push a value in stack, we must check if stack is full or not
        printf("Stack overflow \n") ;
        return ;
    }
    else {
        top ++ ;
        Stack[top] = value ;
    }
}
int Stack_pop (void) {
    if (Stack_is_empty() == 1) {    // before pop a value from stack, we must check if stack is empty or not
        printf("Empty Stack") ;
        return ;
    }
    else {
        int data = Stack[top] ;
        top -- ;
        return data ;
    }
}
void Stack_display (void) {
    if (Stack_is_empty() == 1)    // before display a value from stack, we must check if stack is empty or not
        return ;
    else {
        int i = 0 ;
        for (i=top ; i >=0 ; i--) {           // NOTE : greater than or equal to zero to display the element in index [0]
            printf("values in stack = %d \n" , Stack[i]) ;
        }
    }
}
