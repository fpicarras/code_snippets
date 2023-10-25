#include <stdio.h>

#define N 10000

int main(){
    int num1, num2, temp, id[N];
    //Initialize the id array
    for(int i = 0; i<N; i++) id[i] = i;

    //While the user is inputinf data
    while(scanf("%d %d", &num1, &num2) == 2){
        if(id[num1] == id[num2]) continue;
        
        temp = id[num1];
        for(int i = 0; i < N; i++)
            if(id[i] == temp) id[i] = id[num2];

        printf("\t%d %d\n", num1, num2);
    }
    //Union is Slow -> O(N)
    //But to find if two numbers are connected
    //All we have to do is check if id[num1] == id[num2]
}