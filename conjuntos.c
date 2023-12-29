#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tamanho;
    int *elementos;
} Conjunto;

Conjunto uniao(Conjunto A, Conjunto B) {
    Conjunto uniao;
    uniao.tamanho = 0;
    uniao.elementos = malloc(sizeof(int) * (A.tamanho + B.tamanho));

    for (int i = 0; i < A.tamanho; i++) {
        uniao.elementos[uniao.tamanho++] = A.elementos[i];
    }

    for (int i = 0; i < B.tamanho; i++) {
        int elemento = B.elementos[i];
        int encontrado = 0;
        for (int j = 0; j < uniao.tamanho; j++) {
            if (uniao.elementos[j] == elemento) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            uniao.elementos[uniao.tamanho++] = elemento;
        }
    }

    return uniao;
}

Conjunto interseccao(Conjunto A, Conjunto B) {
    Conjunto interseccao;
    interseccao.tamanho = 0;
    interseccao.elementos = malloc(sizeof(int) * A.tamanho);

    for (int i = 0; i < A.tamanho; i++) {
        int elemento = A.elementos[i];
        for (int j = 0; j < B.tamanho; j++) {
            if (elemento == B.elementos[j]) {
                interseccao.elementos[interseccao.tamanho++] = elemento;
                break;
            }
        }
    }

    return interseccao;
}

void impressao(Conjunto conjunto) {
    printf("Elementos do conjunto:\n");
    for (int i = 0; i < conjunto.tamanho; i++) {
        printf("%d ", conjunto.elementos[i]);
    }
    printf("\n");
}

int main() {
    Conjunto A, B;

    scanf("%d", &A.tamanho);
    A.elementos = malloc(sizeof(int) * A.tamanho);

    for (int i = 0; i < A.tamanho; i++) {
        scanf("%d", &A.elementos[i]);
    }

    scanf("%d", &B.tamanho);
    B.elementos = malloc(sizeof(int) * B.tamanho);

    for (int i = 0; i < B.tamanho; i++) {
        scanf("%d", &B.elementos[i]);
    }

    Conjunto uniaoAB = uniao(A, B);
    Conjunto interseccaoAB = interseccao(A, B);

    impressao(uniaoAB);
    impressao(interseccaoAB);

    free(A.elementos);
    free(B.elementos);
    free(uniaoAB.elementos);
    free(interseccaoAB.elementos);

    return 0;
}
