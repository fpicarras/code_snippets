#include "doubleLinkedList.h"

typedef struct _D_node{
    struct _D_node *next;
    struct _D_node *prev;
    Item content;
}DNode;

typedef struct _D_linkedList{
    DNode *head;
    DNode *tail;
}DList;

DNode *createNode(Item i){
    DNode *new = (DNode*)calloc(1, sizeof(DNode));
    if(new == NULL) return NULL;
    new->content = i;
    return new;
}

DList *createDoubleList(){
    DList *new = NULL;
    new = (DList*)calloc(1, sizeof(DList));
    return new;
}

void deleteDoubleList(DList *l, void (*freeItem)(Item i)){
    DNode *aux1 = NULL, *aux2 = NULL;
    aux1 = l->head;
    while(aux1 != NULL){
        freeItem(aux1->content);
        aux2 = aux1;
        aux1 = aux1->next;
        free(aux2); aux2 = NULL;
    }
    free(l);
}

void D_appendStart(DList *l, Item i){
    DNode *aux = NULL;
    if(l->head == NULL){
        l->head = createNode(i);
        l->tail = l->head;
        return;
    }else{
        (aux = createNode(i))->next = l->head;
        l->head->prev = aux;
        l->head = aux;
        return;
    }
}

void D_appendEnd(DList *l, Item i){
    DNode *aux = NULL;
    if(l->head == NULL){
        l->head = createNode(i);
        l->tail = l->head;
        return;
    }else{
        (aux = createNode(i))->prev = l->tail;
        l->tail->next = aux;
        l->tail = aux;
        return;
    }
}

Item D_popHead(DList *l){
    return deleteNode(l, D_getHead(l));
}

Item D_popTail(DList *l){
    return deleteNode(l, D_getTail(l));
}

DNode *D_getHead(DList *l){
    if(l == NULL) return NULL;
    return l->head;
}

DNode *D_getTail(DList *l){
    if(l == NULL) return NULL;
    return l->tail;
}

DNode *D_getNext(DNode *n){
    if(n == NULL) return NULL;
    return n->next;
}

DNode *D_getPrev(DNode *n){
    if(n == NULL) return NULL;
    return n->prev;
}

Item D_getItem(DNode *n){
    if(n == NULL) return NULL;
    return n->content;
}

Item replaceItem(DNode *n, Item i){
    Item aux = NULL;
    if(n == NULL) return NULL;
    aux = n->content;
    n->content = i;
    return aux;
}

Item deleteNode(DList *l, DNode *n){
    Item aux = NULL;
    DNode *next = NULL, *prev = NULL;
    if(n == NULL) return NULL;

    if(n == l->head) l->head = l->head->next;
    if(n == l->tail) l->tail = l->tail->prev;
    aux = n->content;
    next = n->next; prev = n->prev;
    free(n); n = NULL;
    if(next != NULL) next->prev = prev;
    if(prev != NULL) prev->next = next;
    return aux;
}