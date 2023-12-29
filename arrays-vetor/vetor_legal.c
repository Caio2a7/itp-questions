#include <stdio.h>

int vetor_legal(int vetor[], int tamanho) {
    for (int j = 0; j < tamanho - 1; j++) {
        int sub = vetor[j+1] - vetor[j];
        if (sub == 0) {
        } else if (sub % 2 != 0) {
            printf("Chato\n");
            return 0;
        }
    }
    printf("Legal\n");
    return 1;
}

int main() {
    int tamanho;
    printf("");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++) {
        printf("");
        scanf("%d", &vetor[i]);
    }
    vetor_legal(vetor, tamanho);
    return 0;
}