//P altura do pulo N numero de canos
//N array altura de cada cano
//o sapo sempre começa no cano da esquerda e termina no final
//O sapo só passa pelo cano se a altura dele for maior que a do cano
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int frog_jump_height, pipes_qtd;
    int *pipes_height;
} Game;

char *game_result(Game frog_game){
    for(int i = 0; i < frog_game.pipes_qtd-1; i++){
        printf("%d | %d\n", frog_game.pipes_height[i+1], frog_game.pipes_height[i]+frog_game.frog_jump_height);
        if(frog_game.pipes_height[i+1] > frog_game.pipes_height[i]+frog_game.frog_jump_height){
            return "GAME OVER";
        }
    }
    return "YOU WIN";
}

int main(void){
    Game frog_game;
    scanf("%d %d", &frog_game.frog_jump_height, &frog_game.pipes_qtd);
    frog_game.pipes_height = (int *)malloc(sizeof(int) * frog_game.pipes_qtd);
    for(int i = 0; i < frog_game.pipes_qtd; i++){
        scanf("%d", &frog_game.pipes_height[i]);
    }
    char *result = game_result(frog_game);
    printf("%s", result);
    
    return 0;
}
