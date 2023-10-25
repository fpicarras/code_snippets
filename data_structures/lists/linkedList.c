#include "linkedList.h"

typedef struct _node{
    Item content;
    struct _node *next;
}Node;

typedef struct _linkedList{
    struct _node *head;
    struct _node *tail;
}List;

List *createList(){
    List *new = (List*)calloc(1, sizeof(List));
    if(new == NULL) return NULL;

    new->head = NULL; new->tail = NULL;
    return new;
}

void deleteList(List *l, void (*freeItem)(Item i)){
    Node *aux1 = NULL, *aux2 = NULL;
    aux1 = l->head;
    while(aux1 != NULL){
        freeItem(aux1->content);
        aux2 = aux1;
        aux1 = aux1->next;
        free(aux2); aux2 = NULL;
    }
    free(l);
}

Node *createNode(Item i){
    Node *new = (Node*)calloc(1, sizeof(Node));
    if(new != NULL){
        new->content = i;
        return new;
    }
    return NULL;
}

void appendStart(List *l, Item i){
    Node *aux = NULL;
    if(l->head == NULL){
        l->head = createNode(i);
        l->tail = l->head;
        return;
    }else {
        aux = createNode(i);
        aux->next = l->head;
        l->head = aux;
        return;
    }
}

void appendEnd(List *l, Item i){
    Node *aux = NULL;
    if(l->head == NULL){
        l->head = createNode(i);
        l->tail = l->head;
        return;
    }else {
        aux = createNode(i);
        l->tail->next = aux;
        return;
    }
}

Item popHead(List *l){
    Node *node_aux = NULL;
    Item item_aux = NULL;

    if(l->head == NULL) return NULL;

    node_aux = l->head; item_aux = node_aux->content;
    l->head = l->head->next;
    free(node_aux); node_aux = NULL;
    //Does not free the head's content!!!
    return(item_aux);
}

Node *getHead(List *l){
    if(l == NULL) return NULL;
    return l->head;
}

Node *getTail(List *l){
    if(l == NULL) return NULL;
    return l->tail;
}

Node *getNext(Node *n){
    if(n == NULL) return NULL;
    return n->next;
}

Item getItem(Node *n){
    if(n == NULL) return NULL;
    return n->content;
}

Item replaceItem(Node *n, Item i){
    Item aux = NULL;
    if(n == NULL) return NULL;
    aux = n->content;
    n->content = i;
    return aux;
}