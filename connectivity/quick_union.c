#include <stdio.h>

#define N 10000

int main(){
    int num1, num2, temp1, temp2, id[N];
    //Initialize the id array
    for(int i = 0; i<N; i++) id[i] = i;

    //While the user is inputing data
    while(scanf("%d %d", &num1, &num2) == 2){
        temp1 = num1; temp2 = num2;
        while(temp1 != id[temp1]) temp1 = id[temp1];
        while(temp2 != id[temp2]) temp2 = id[temp2];

        if(temp1 == temp2) continue;
        id[temp1] = temp2;

        printf("\t%d %d\n", num1, num2);
    }
    //Union is Faster -> O(1)
    //But to find if two numbers are connected
    //We have to find if they have the same root
}