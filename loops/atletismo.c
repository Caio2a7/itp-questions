#include <stdio.h>

int main() {
    float tempo;
    float requisito;
    int series = 1;
    int competidores = 0;

    printf("");
    scanf("%f", &requisito);

    printf("");

    while (1) {
        scanf("%f", &tempo);

        if (tempo == -1) {
            break; 
        }

        if (tempo <= requisito) {
            competidores++;
        }
    }
    if (competidores%8) {
        series = series+competidores/8;
    }
    else if(competidores == 0) {
        series = 0;
    }
        

    printf("%d %d", competidores, series);

    return 0;
}
