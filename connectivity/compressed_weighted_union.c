#include <stdio.h>

#define N 10000

int main(){
    int num1, num2, temp1, temp2, t, x, id[N], sz[N];
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

        printf("\t%d %d\n", num1, num2);
    }
}