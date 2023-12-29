#include <stdio.h>
#include <math.h>

int main() {
    int componente;
    
    while (1) {
        printf("");
        scanf("%d", &componente);

        if (componente == 0) {
            break;
        }

        printf("Matriz para componente %d:\n", componente);

        for (int i = 0; i < componente; i++) {
            for (int j = 0; j < componente; j++) {
                double valor = (double)pow(2, i + j);
                printf("%6.lf", valor);

                if (j < componente - 1) {
                    printf(" "); // Espaço entre os números
                }
            }
            printf("\n"); // Nova linha para a próxima linha da matriz
        }
    }

    return 0;
}
