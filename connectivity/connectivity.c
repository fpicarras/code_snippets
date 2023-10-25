#include "connectivity.h"

typedef struct _connections{
    int *id;
    int *sz;
    int N;
}Connections;

Connections *newConn(int size){
    Connections *new = NULL;
    if((new = (Connections*)malloc(sizeof(Connections))) == NULL) return NULL;
    if((new->id = (int*)malloc(sizeof(int)*size)) == NULL) return NULL;
    if((new->sz = (int*)malloc(sizeof(int)*size)) == NULL) return NULL;

    new->N = size;
    for(int i = 0; i<size; i++){
        new->id[i] = i;
        new->sz[i] = 1;
    }
    return new;
}

void delConn(Connections *conn){
    free(conn->id); free(conn->sz); free(conn);
    return;
}

int isConnected(Connections *conn, int num1, int num2){
    int temp1 = 0, temp2 = 0;
    if(num1 == num2) return 1;
    if(num1 < 0 || num1 >= conn->N || num2 < 0 || num2 >= conn->N) return 0;

    temp1 = num1; temp2 = num2;
    while(temp1 != conn->id[temp1]) temp1 = conn->id[temp1];
    while(temp2 != conn->id[temp2]) temp2 = conn->id[temp2];
    if(temp1 == temp2) return 1;
    else return 0;
}

void addConn(Connections *conn, int num1, int num2){
    int temp1 = 0, temp2 = 0, t, x;
    int *sz = conn->sz, *id = conn->id;
    if(!isConnected(conn, num1, num2)) return;

    if(sz[temp1] < sz[temp2]){
        id[temp1] = temp2; sz[temp2] += sz[temp1]; t = temp2;
    }else {
        id[temp2] = temp1; sz[temp1] += sz[temp2]; t = temp1;
    }

    //Now each vertice will point to the root
    for(temp1 = num1; temp1 != id[temp1]; temp1 = x){
        x = id[temp1]; id[temp1] = t;
    }
    for(temp2 = num2; temp2 != id[temp2]; temp2 = x){
        x = id[temp2]; id[temp2] = t;
    }
}