#include <string.h>

int binSearch(int arr[], int alvo, int i, int f){
    int m;
    while(f >= i){
        m = (i+f)/2;

        if(alvo == arr[m]) return m;
        if(alvo < arr[m]) f = m-1;
        else i = m+1;
    }
    return -1;
}

int recursiveBinSearch(int arr[], int alvo, int i, int f){
    int m;
    if(f >= i){
        m = (i+f)/2;

        if(alvo == arr[m]) return m;
        if(alvo < arr[m])
            return recursiveBinSearch(arr, alvo, i, m-1);
        return recursiveBinSearch(arr, alvo, m+1, f);
    }
    return -1;
}

int strBinSearch(char *arr[], char *alvo, int i, int f){
    int m;
    while( f >= i){
        m = (i+f)/2;

        if(strcmp(alvo, arr[m]) == 0) return m;
        if(strcmp(alvo, arr[m]) < 0) f = m-1;
        else i = m+1;
    }
    return -1;
}