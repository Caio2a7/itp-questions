#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[200];
    int gols[2];
} Time;

void calculo_pontos(Time times[], int quantidade_times) {
    int flag;
    do {
        flag = 0;
        for (int i = 0; i < quantidade_times - 1; i++) {
            if (times[i].gols[0] < times[i + 1].gols[0]) {
                Time temp = times[i];
                times[i] = times[i + 1];
                times[i + 1] = temp;
                flag = 1;
            }
        }
    } while (flag);
}

void impressao_times(Time times[], int quantidade_times) {
    for (int i = 0; i < quantidade_times; i++) {
        printf("%d - %s\nGols marcados: %d\nGols sofridos: %d\n", i + 1, times[i].nome, times[i].gols[0], times[i].gols[1]);
    }
}

int main() {
    int quantidade_times;

    printf("");
    scanf("%d", &quantidade_times);

    Time times[quantidade_times];
    for (int i = 0; i < quantidade_times; i++) {
        printf("");
        scanf(" %199[^\n]", times[i].nome);
        printf("");
        scanf("%d", &times[i].gols[0]);
        printf("");
        scanf("%d", &times[i].gols[1]);
    }

    calculo_pontos(times, quantidade_times);
    impressao_times(times, quantidade_times);

    return 0;
}
