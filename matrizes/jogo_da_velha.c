#include <stdio.h>
void avaliacao_jogadas(char tabuleiro[][3], int jogadas){
    int pos_x, pos_y;
    char jogada;
    char testes_tabuleiro[][3] = {{'*', '*', '*'},
                               {'*', '*', '*'},
                               {'*', '*', '*'}};
    int jogada_boa = 0;
    for (int i = 0; i < jogadas; i++){
        printf("");
        scanf("%d %d %c", &pos_x, &pos_y, &jogada);
        testes_tabuleiro[pos_x-1][pos_y-1] = jogada;
        if (tabuleiro[pos_x-1][pos_y-1] == 'X'||tabuleiro[pos_x-1][pos_y-1]=='O') {
                printf("Jogada inválida!\n");
            }
        else if (testes_tabuleiro[pos_x-1][pos_y-1] == 'X' || testes_tabuleiro[pos_x-1][pos_y-1] == 'O') {
            for (int m = 0; m < 3; m++) {
                //Varrendo as diagonais para um X central
                if (testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1+m][pos_y-1+m] && testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1+m+m][pos_y-1+m+m]|| testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1-m][pos_y-1+m] && testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1-(m+m)][pos_y-1+(m+m)]) {
                    printf("Boa jogada, vai vencer!\n");
                    jogada_boa++;
                    break;
                }
                //Varrendo as diagonais para um X de pontas
                else if (testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1+m][pos_y-1+m] && testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1-m][pos_y-1-m]|| testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1+m][pos_y-1-m] && testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1-m][pos_y-1+m]){
                    printf("Boa jogada, vai vencer!\n");
                    jogada_boa++;
                    break;
                }
                //varrendo em cima e em baixo
                else if (testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1+m][pos_y-1] && testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1-m][pos_y-1]){
                    printf("Boa jogada, vai vencer!\n");
                    jogada_boa++;
                    break;
                }
                else if (testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1-m][pos_y-1] && testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1-m-m][pos_y-1]){
                    printf("Boa jogada, vai vencer!\n");
                    jogada_boa++;
                    break;
                }
                //Varrendo a esquerda e direita
                else if (testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1][pos_y-1-m] && testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1][pos_y-1+m]){
                    printf("Boa jogada, vai vencer!\n");
                    jogada_boa++;
                    break;
                }
                else if (testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1][pos_y-1-m] && testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1][pos_y-1-m-m]){
                    printf("Boa jogada, vai vencer!\n");
                    jogada_boa++;
                    break;
                }
                else if (testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1][pos_y-1+m] && testes_tabuleiro[pos_x-1][pos_y-1] == tabuleiro[pos_x-1][pos_y-1+m+m]){
                    printf("Boa jogada, vai vencer!\n");
                    jogada_boa++;
                    break;
                }
            }
            if (jogada_boa == 0) { printf("Continua o jogo.\n"); }
            else { }
            jogada_boa = 0;
        }
    }       
}

int main() {
    char tabuleiro[3][3];
    int jogadas;
    for (int i = 0; i < 3; i++) {
        printf("");
        scanf(" %c %c %c", &tabuleiro[i][0], &tabuleiro[i][1], &tabuleiro[i][2]);
    }
    printf("");
    scanf("%d", &jogadas);
    avaliacao_jogadas(tabuleiro, jogadas);
    return 0;
}