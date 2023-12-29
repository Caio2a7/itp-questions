#include <stdio.h>

int fibonnaci(int num, int limit){
    if(num <= 1){
        return num;
    }
    else{
        return fibonnaci(num-1, limit)+fibonnaci(num-2, limit);
    }
}
void range_fibonnaci(int start, int end,int num, int *qtd_fibo){
    if(num >= start && num <= end){
        *qtd_fibo += 1; 
    }
}

int main(void){
    int n1, n2;
    int *qtd_fibo;
    *qtd_fibo = 0;
    scanf("%d %d", &n1, &n2);
    
    for(int i = 0; i < n2; i++){
        int fibo = fibonnaci(i, n2);
        if(fibo > n2){
            break;
        }
        else{
            range_fibonnaci(n1, n2, fibo, qtd_fibo);
        }
        printf("\n%d", fibo);
    }
    printf("\n%d", *qtd_fibo);
    return 0;
}
