#include <stdio.h>

void minipoker(int baralho[][5], int testes){
    //ordenação do baralho
    for(int i = 0; i < testes; i++){
        for(int j = 0; j < 5; j++){
            if(baralho[i][j+1] < baralho[i])
        }
    }
    int regra1 = 0, regrao2 = 0, regrao3 = 0, regra4 = 0, regra5 = 0, regra6 = 0;

}

int main(){
    int testes;
    printf("");
    scanf("%d", &testes);

    int baralho[testes][5];
    for(int i = 0; i < testes; i++){
        for(int j = 0; j < 5; j++){
            printf("");
            scanf("%d ", &baralho[i][j]);
        }
    }
    minipoker(baralho, testes);
    return 0;
} 