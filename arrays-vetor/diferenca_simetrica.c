#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void diferencaSimetrica(int set1[], int set2[], int tamanho1, int tamanho2) {
    int *resultado = malloc((tamanho1 + tamanho2) * sizeof(int));
    int tamanhoResultado = 0;

    for (int i = 0; i < tamanho1; i++) {
        int elemento = set1[i];
        int pertenceA = 0;

        for (int j = 0; j < tamanho2; j++) {
            if (elemento == set2[j]) {
                pertenceA = 1;
                break;
            }
        }

        if (!pertenceA) {
            resultado[tamanhoResultado] = elemento;
            tamanhoResultado++;
        }
    }

    for (int i = 0; i < tamanho2; i++) {
        int elemento = set2[i];
        int pertenceB = 0;

        for (int j = 0; j < tamanho1; j++) {
            if (elemento == set1[j]) {
                pertenceB = 1;
                break;
            }
        }
        if (!pertenceB) {
            resultado[tamanhoResultado] = elemento;
            tamanhoResultado++;
        }
    }
    qsort(resultado, tamanhoResultado, sizeof(int), comparar);
    for (int i = 0; i < tamanhoResultado; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    free(resultado);
}

int main() {
    int tamanho1, tamanho2;
    
    printf("");
    scanf("%d %d", &tamanho1, &tamanho2);

    int set1[tamanho1];
    int set2[tamanho2];

    printf("");
    for (int i = 0; i < tamanho1; i++) {
        scanf("%d", &set1[i]);
    }

    printf("");
    for (int i = 0; i < tamanho2; i++) {
        scanf("%d", &set2[i]);
    }
    diferencaSimetrica(set1, set2, tamanho1, tamanho2);
    return 0;
}