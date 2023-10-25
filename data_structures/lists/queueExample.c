#include "doubleLinkedList.h"
#include <stdio.h>

typedef DList Queue;

Queue *createQueue(){
    return (Queue*)createDoubleList();
}

void deleteQueue(Queue *q, void (*freeItem)(Item i)){
    /**
     * When deleting the queue, the function freeItem
     * will free all the allocated memory of the Item,
     * you can also just set it as a simple enter and return
     * so that you don't free any of the Items!
    */
    deleteDoubleList((DList*)q, freeItem);
}

void push(Queue* q, Item i){
    D_appendStart((DList*)q, i);
}

/**
 * The following funtions return NULL if the queue is empty!
*/
Item pop(Queue* q){
    return D_popTail((DList*)q);
}

Item peek(Queue *q){
    return D_getItem(D_getTail((DList*)q));
}

/**
 * In this case, the data that we are sending are int*
 * (static) so we don't need to free them.
*/
void freeItem(Item i){
    return;
}

int main(){
    Queue *queue = createQueue();
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    for(int i = 0; i<8; i+=2){
        push(queue, (Item)(arr+i+1));
        push(queue, (Item)(arr+i));
    }

    for(int i = 0; i<8; i++){
        printf("%d\n", *(int*)pop(queue));
    }

    deleteQueue(queue, freeItem);

    return 0;
}