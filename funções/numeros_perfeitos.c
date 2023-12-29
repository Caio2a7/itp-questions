#include <stdio.h>
int perfeitos(int numero){
    int divisores = 0;
    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) {
            divisores = divisores+i;
        }
    }
    if (divisores == numero) {
        printf("%d eh perfeito\n", numero);
    }
    else {
        printf("%d não eh perfeito\n", numero);
    }
    return 0;
}

int main () {
    int loops;
    int numero[loops];
    printf("");
    scanf("%d", &loops);
    for (int i = 0; i < loops; i++) {
        printf("");
        scanf("%d", &numero[i]);
    }
    for (int j = 0; j < loops; j++) {
        perfeitos(numero[j]);
    }
    return 0;
}