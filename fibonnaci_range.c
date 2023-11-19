#include <stdio.h>

int fibonnaci(int num, int limit){
    if(num > limit){
        return num;
    }
    else{
        return fibonnaci(num-1, limit)+fibonnaci(num-2, limit);
    }
}

int main(void){
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    print("%d %d", n1, n2);
    for(int i = 0; i < n2; i++){
        int fibo = fibonnaci(i, n2);
        printf("\n%d", fibo);
    }

    return 0;
}