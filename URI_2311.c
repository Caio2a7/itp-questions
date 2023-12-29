#include <stdio.h>
#include <string.h>

void calculo_pontos(int mergulhadores, char mergulhador[][100], double dificuldade[], double notas[][7]) {
    for (int i = 0; i < mergulhadores; i++) {
        double maior = notas[i][0];
        double menor = notas[i][0];
        
        for (int j = 0; j < 7; j++) {
            if (notas[i][j] > maior) {
                maior = notas[i][j];
            }
            
            if (notas[i][j] < menor) {
                menor = notas[i][j];
            }
        }
        
        // Removendo o maior e o menor valor
        double soma = 0;
        for (int j = 0; j < 7; j++) {
            if (notas[i][j] != maior && notas[i][j] != menor) {
                soma += notas[i][j];
            }
        }
        
        double pontuacao = soma * dificuldade[i];
        printf("Mergulhador %d - Pontuação: %.2lf\n", i + 1, pontuacao);
    }
}

int main() {
    int mergulhadores;

    printf("Número de mergulhadores: ");
    scanf("%d", &mergulhadores);
    getchar();

    double dificuldade[mergulhadores];
    double notas[mergulhadores][7];
    char mergulhador[mergulhadores][100];

    for (int i = 0; i < mergulhadores; i++) {
        printf("Nome do mergulhador %d: ", i + 1);
        fgets(mergulhador[i], sizeof(mergulhador[i]), stdin);

        printf("Dificuldade do mergulhador %d: ", i + 1);
        scanf("%lf", &dificuldade[i]);

        for (int j = 0; j < 7; j++) {
            printf("Nota %d do mergulhador %d: ", j + 1, i + 1);
            scanf("%lf", &notas[i][j]);
        }
        
        getchar(); 
    }
    
    calculo_pontos(mergulhadores, mergulhador, dificuldade, notas);
    return 0;
}
