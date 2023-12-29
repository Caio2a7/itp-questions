#include <stdio.h>

int main() {
    int largura;
    printf("");
    scanf("%d", &largura);
    int piramide[largura][largura];
    int valor_armazenamento = 1;
    int camadas = 0;
    for (int i = 0; i < largura; i++) {
        for (int j = 0; j < largura; j++) {
            for (int m = 1; m <= largura; m++) {
                if (i >= m && i < largura-m && j >= m && j < largura-m) {
                    valor_armazenamento += 1;
                }
                else {
                }
            }
            piramide[i][j] = valor_armazenamento;
            valor_armazenamento = 1;
        }
    }
    for (int i = 0; i < largura; i++){
        for (int j = 0; j < largura; j++){
            printf("%d ", piramide[i][j]);
        }
    printf("\n");
    }
}