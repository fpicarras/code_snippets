#include "linkedList.h"
#include <stdio.h>

typedef List Stack;

Stack *createStack(){
    return (Stack*)createList();
}

void deleteStack(Stack *s, void (*freeItem)(Item i)){
    deleteList((List*)s, freeItem);
    return;
}

void push(Stack *s, Item i){
    appendStart((List*)s, i);
    return;
}

Item pop(Stack *s){
    return popHead((List*)s);
}

Item peek(Stack *s){
    //It's like a popHead, but without deleting the ead Node.
    return getItem(getHead((List*)s));
}

void freeItem(){
    return;
}

int main(){
    int arr[7] = {1, 2, 3, 5, 7, 9, 11};

    Stack *st = createStack();

    for(int i = 0; i<sizeof(arr)/sizeof(int); i++){
        push(st, (Item)(arr+i));
    }
    pop(st);
    printf("%d\n", *(int*)pop(st));
    printf("%d\n", *(int*)pop(st));

    deleteStack(st, freeItem);

    return 0;
}