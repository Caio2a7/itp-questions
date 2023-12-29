#include <stdio.h>

int main() {
    int quantidade_numeros;
    int lista[quantidade_numeros];

    printf("");
    scanf("%d", &quantidade_numeros);

    printf("");
    for (int j = 0; j < quantidade_numeros; j++) {
        scanf("%d ", &lista[j]);
    }
    for (int i = 1; i < quantidade_numeros; i++) {
        if (lista[i-1] > lista[i]) {
            int temp = lista[i];
            lista[i] = lista[i-1];
            lista[i-1] = temp;
        }
        for (int i = 0; i < sizeof(lista); i++) {
        printf("%d", lista[i]);
        }
    }
    return 0;
}