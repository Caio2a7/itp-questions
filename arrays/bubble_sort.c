#include <stdio.h>

void bubble_sort(int lista[], int tamanho_lista) {
    int ordenado = 0;
    for (int i = 0; i < tamanho_lista; i++) {
            printf("%d ", lista[i]);
        }
        printf("\n");
    do {
        ordenado = 0;
        // Aqui realizamos a troca de valores menores pelos maiores
        for (int i = 1; i < tamanho_lista; i++) { 
            if (lista[i - 1] > lista[i]) {
                int valor_salvo = lista[i];
                lista[i] = lista[i - 1];
                lista[i - 1] = valor_salvo;
                ordenado = 1; //Usamos essa variável como controle para esse loop 
            }
        }
        if (ordenado == 0) { break; }
        // Imprimir a lista após cada passagem
        for (int i = 0; i < tamanho_lista; i++) {
            printf("%d ", lista[i]);
        }
        printf("\n");
    } while (ordenado); 
}

int main() {
    int tamanho_lista;

    // Solicitar o tamanho da lista ao usuário
    printf("");
    scanf("%d", &tamanho_lista);

    int lista[tamanho_lista];

    printf("");
    for (int i = 0; i < tamanho_lista; i++) {
        scanf("%d", &lista[i]);
    }

    bubble_sort(lista, tamanho_lista);

    return 0;
}
