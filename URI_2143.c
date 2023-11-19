//Esse programa funcionará como um display gráfico de um radar de navio
//Ou seja, o receptor de ondas de radar por meio da entrada de input (de usuário) irá lhe passar
//a o range do radar seguido do numéro, escala em quilometros, depois
//parâmetro o seguido da posicao e que tipo de objeto foi detectado
//e ira enviando as posicoes e tipos até o parâmetro f para o programa juntar todos os dados
//e retornar uma matriz gráfica da área e avisos sobre
//- se um navio estiver a menos de 1 km de distancia ira retornar perigo
//- se uma rocha estiver a menos de 50 metros de distancia ira retornar cuidado
//- se qualquer coisa estiver a menos de 10 metros ira retornar PERIGO MAXIMO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_SIZE 8

char **radar_display(int range){
    range *= 2;  //aumentando a precisão da escala do display, se for 5 km o range, antes a precisão seria de uma área 
                //1km por célula possível de ter o objeto, agora aumentamos a precisão para 500 metros
    char ***radar;
    radar = (char **)malloc(sizeof(char *) * range);
    for(int i = 0; i < range; i++){
        radar[i] = (char *)malloc(sizeof(char) * range * MAX_STR_SIZE);
    }
    radar[range/2][range/2] = "* ";
    for(int i = 0; i < range; i++){
        for(int j = 0; j < range; j++){
            radar[i][j] = "~ ";
        }
    }
    radar[range/2][range/2] = "* ";
    for(int i = 0; i < range; i++){
        for(int j = 0; j < range; j++){
            printf("%s", radar[i][j]);
        }
        printf("\n");
    }
    //setando a posição central do navio
    return radar_display;
}

int main(void){
    char parametro;
    int x, y; 
    int range;
    scanf("%d", &range);
    radar_display(range);
    /*
    while(parametro != 'f'){
        scanf("%c %d %d", &parametro, &x, &y);
    }*/
    return 0;
}