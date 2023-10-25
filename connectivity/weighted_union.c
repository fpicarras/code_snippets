#include <stdio.h>

#define N 10000

int main(){
    int num1, num2, temp1, temp2, id[N], sz[N];
    //Initialize the id array
    for(int i = 0; i<N; i++){
        id[i] = i;
        sz[i] = 1;
    }

    //While the user is inputing data
    while(scanf("%d %d", &num1, &num2) == 2){
        temp1 = num1; temp2 = num2;
        while(temp1 != id[temp1]) temp1 = id[temp1];
        while(temp2 != id[temp2]) temp2 = id[temp2];

        if(temp1 == temp2) continue;
        if(sz[temp1] < sz[temp2]){
            id[temp1] = temp2; sz[temp2] += sz[temp1];
        }else {
            id[temp2] = temp1; sz[temp1] += sz[temp2];
        }

        printf("\t%d %d\n", num1, num2);
    }
}