#include <stdio.h>

typedef struct{
    char time_nome[200];
    int time_numeros[5];
    int time_pontos;
    int saldo_gols;
    int jogos;
} Time;

Time calculo_pontos(Time times[], int quantidade_times){
    for(int i = 0; i < quantidade_times; i++){
        times[i].time_pontos = (times[i].time_numeros[0]*3) + times[i].time_numeros[1];
        times[i].saldo_gols = (times[i].time_numeros[3] - times[i].time_numeros[4]);
        times[i].jogos = (times[i].time_numeros[0] + times[i].time_numeros[1] + times[i].time_numeros[2]);
    }
    int flag;
    do {
        flag = 0;
        for (int i = 0; i < quantidade_times - 1; i++) { 
            if (times[i].time_pontos < times[i+1].time_pontos) {  
                Time temp = times[i];
                times[i] = times[i+1];
                times[i+1] = temp;
                flag = 1;
            }
            else if (times[i].time_pontos == times[i+1].time_pontos){
                if(times[i].time_numeros[0] < times[i+1].time_numeros[0]){
                    Time temp = times[i];
                    times[i] = times[i+1];
                    times[i+1] = temp;
                    flag = 1;
                }
            }
        }
    } while (flag);
    do{
        flag = 0;
        for (int i = 0; i < quantidade_times - 1; i++) {
            if(times[i].time_pontos == times[i+1].time_pontos && times[i].saldo_gols < times[i+1].saldo_gols && times[i].time_numeros[0] == times[i+1].time_numeros[0]){
                Time temp = times[i];
                times[i] = times[i+1];
                times[i+1] = temp;
                flag = 1;
            }
        }
    } while(flag);
    return times[quantidade_times];
}
void impressao_times(Time times[], int quantidade_times){
    printf("Tabela do campeonato:\nNome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols");
    for(int i = 0; i < quantidade_times; i++){
        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d", times[i].time_nome, times[i].time_pontos, times[i].jogos, times[i].time_numeros[0], 
        times[i].time_numeros[1], times[i].time_numeros[2], times[i].time_numeros[3], 
        times[i].time_numeros[4], times[i].saldo_gols);
    }
    printf("\n\nTimes na zona da libertadores:");
    for(int i = 0; i < 6; i++){
        printf("%s", times[i].time_nome);
    }
    printf("\n\nTimes rebaixados:");
    for(int i = 1; i < 5; i++){
        printf("%s", times[quantidade_times-i].time_nome);
    }
}
int main(){
    int quantidade_times;
    printf("");
    scanf("%d", &quantidade_times);
    Time times[quantidade_times];
    for(int i = 0; i < quantidade_times; i++){
        printf("");
        scanf("%200[^;]; %d %d %d %d %d", times[i].time_nome, &times[i].time_numeros[0], 
        &times[i].time_numeros[1], &times[i].time_numeros[2], &times[i].time_numeros[3], 
        &times[i].time_numeros[4]);
    }
    calculo_pontos(times, quantidade_times);
    impressao_times(times, quantidade_times);
    return 0;
}