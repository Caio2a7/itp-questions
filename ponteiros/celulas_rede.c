#include <stdio.h>
#include <stdlib.h>

int* get_range(int tamanho, int celulas[], int distancia, int user, int *tamanho_conectadas) {
    int conectado = 0;
    int *celulas_conectadas = NULL;

    for (int i = 0; i < tamanho; i++) {
        int calculo_distancia = user - celulas[i];
        if (calculo_distancia <= distancia && calculo_distancia >= -distancia) {
            conectado++;
            celulas_conectadas = realloc(celulas_conectadas, sizeof(int) * conectado);
            celulas_conectadas[conectado - 1] = celulas[i];
            printf("%d - %d\n", celulas[i], celulas_conectadas[conectado - 1]);
        }
    }

    if (conectado == 0) {
        printf("USUARIO DESCONECTADO\n");
    }

    *tamanho_conectadas = conectado; // Atualiza o tamanho do array
    return celulas_conectadas;
}

void impressao(int *celulas_conectadas, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", celulas_conectadas[i]);
    }
    printf("\n");
}

int main() {
    int tamanho, distancia, user;
    scanf("%d %d %d", &tamanho, &distancia, &user);

    int celulas[tamanho];

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &celulas[i]);
    }

    int tamanho_conectadas;
    int *celulas_conectadas = get_range(tamanho, celulas, distancia, user, &tamanho_conectadas);
    impressao(celulas_conectadas, tamanho_conectadas);
    free(celulas_conectadas);
    return 0;
}
