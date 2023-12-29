#include <stdio.h>
#include <stdlib.h>
// a = bq + r
void algoritmo_divisao(int a, int b){
    int q, r;
    r = a % b;
    q = (a-r)/b;
    printf("%d/%d: Quociente: %d Resto: %d\n%d = %d*%d + %d", a, b, q, r, a, b, q, r);
}

int main(void){
    int a, b;

    printf("Me forneça a (dividendo) e b (divisor): \n");
    scanf("%d %d", &a, &b);
    algoritmo_divisao(a, b);


    return 0;
}