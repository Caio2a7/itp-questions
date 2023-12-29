#include <stdio.h>

int main() {
    int numero;
    printf("");
    scanf("%d", &numero);

    if (numero < 1 || numero > 100000) {
        printf("Número fora do intervalo permitido.\n");
        return 1; // Encerra o programa com um código de erro
    }

    int numeros[10]; // Array para armazenar os dígitos
    int tamanho = 0; // Tamanho atual do array

    while (numero > 0) {
        int digito = numero % 10;
        numeros[tamanho] = digito; // Armazena o dígito no array
        tamanho++;
        numero /= 10;
    }

    // Imprime os dígitos na ordem inversa (do último para o primeiro)
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%d\n", numeros[i]);
    }

    return 0; // Programa encerrado com sucesso
}