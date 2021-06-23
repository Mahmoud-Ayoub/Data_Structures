## Circular Queue 
is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called 'Ring Buffer'. 

![Circular-queue](https://user-images.githubusercontent.com/84600209/123148122-25240a80-d460-11eb-8f57-214a8980ea72.png)

## Applications of Circular Queue : 
* Memory Management
* Process Scheduling

## Functions implemented :
* **EnQueue** : Adds an item in the queue. If the queue is full, then it is said to be a Queue Overflow.
* **DeQueue** : Removes an item from the queue. If the queue is empty, then it is said to be an Empty Queue.
* **IsFull** : Returns True if the queue is Full, else False (Note : queue implementation using linked list has no Isfull function as it is dynamic memory allocation).
* **IsEmpty** : Returns True if the queue is Empty, else False.


![Circular-queue_1](https://user-images.githubusercontent.com/84600209/123148933-083c0700-d461-11eb-94d1-4ba14fcf1b1d.png)
