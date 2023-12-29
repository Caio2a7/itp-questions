#include <stdio.h>
#include <strings.h>
#pragma GCC diagnostic ignored "-Wformat-zero-length"

typedef struct {
    char modelo[199];
    int memoria;
    float processador, camera, bateria;
} Smartphone;

void impressao(Smartphone smartphone) {
    printf("Modelo: %s\nMemoria: %dGB\nProcessador: %.2fGhz\nCamera: %.2fMPixels\nBateria: %.2fmA\n\n",
           smartphone.modelo, smartphone.memoria, smartphone.processador, smartphone.camera, smartphone.bateria);
}

void cadastro_smartphones(int qtd_celulares, Smartphone smartphone[qtd_celulares], Smartphone reqMin) {
    int match = 0;
    for (int i = 0; i < qtd_celulares; i++) {
        if (smartphone[i].memoria >= reqMin.memoria &&
            smartphone[i].processador >= reqMin.processador &&
            smartphone[i].camera >= reqMin.camera &&
            smartphone[i].bateria >= reqMin.bateria) {
            match++;
            impressao(smartphone[i]); // Print the details of the matched smartphone
        }
    }
    printf("%d smartphones encontrados.", match);
}

int main() {
    char cadastro[2];
    Smartphone smartphone[10];
    int k = 0;

    while (1) {
        printf("");
        scanf(" %c", &cadastro[0]);

        if (cadastro[0] == 'n') {
            break;
        }
        printf("");
        scanf(" %199[^\n]", smartphone[k].modelo);
        printf("");
        scanf("%d", &smartphone[k].memoria);
        printf("");
        scanf("%f", &smartphone[k].processador);
        printf("");
        scanf("%f", &smartphone[k].camera);
        printf("");
        scanf("%f", &smartphone[k].bateria);
        k++;
    }
    Smartphone reqMin;
    printf("");
    scanf("%d", &reqMin.memoria);
    printf("");
    scanf("%f", &reqMin.processador);
    printf("");
    scanf("%f", &reqMin.camera);
    printf("");
    scanf("%f", &reqMin.bateria);
    
    cadastro_smartphones(k, smartphone, reqMin);

    return 0;
}
#pragma GCC diagnostic warning "-Wformat-zero-length"