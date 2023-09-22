#include <stdio.h>
void avaliacao_jogadas(char tabuleiro[][3], int jogadas){
    int pos_x, pos_y;
    char jogada;
    char testes_tabuleiro[][3] = {{'*', '*', '*'},
                               {'*', '*', '*'},
                               {'*', '*', '*'}};
    int var_jogada_regular = 0;
    for (int i = 0; i < jogadas; i++){
        printf("");
        scanf("%d %d %c", &pos_x, &pos_y, &jogada);
        testes_tabuleiro[pos_x-1][pos_y-1] = jogada;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", testes_tabuleiro[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < pos_x; i++) {
        for (int j = 0; j < pos_y; j++) {
            if (testes_tabuleiro[i][j] == tabuleiro[i][j]) {
                printf("Jogada inválida!\n");
                break;
            }
            else if (testes_tabuleiro[i][j] == 'X' || testes_tabuleiro[i][j] == 'O') {
                for (int m = 0; m < 3; m++) {
                    //Varendo as diagonais por outro X
                    if (testes_tabuleiro[i][j] == tabuleiro[i+m][j-m] || testes_tabuleiro[i][j] == tabuleiro[i-m][j+m]) {
                        printf("Boa jogada, vai vencer!\n");
                        break;
                    }
                    //varrendo em cima e em baixo
                    else if (testes_tabuleiro[i][j] == tabuleiro[i-m][j] || testes_tabuleiro[i][j] == tabuleiro[i+m][j]) {
                        printf("Boa jogada, vai vencer!\n");
                        break;
                    }
                    //Varrendo a esquerda e direita
                    else if (testes_tabuleiro[i][j] == tabuleiro[i][j-m] || testes_tabuleiro[i][j] == tabuleiro[i][j+m]) {
                        printf("Boa jogada, vai vencer!\n");
                        break;
                    }
                    else {
                        var_jogada_regular++;
                        }
                    }
            }
            if (var_jogada_regular == 3) {
                printf("Continua o jogo.\n");
            }
            var_jogada_regular = 0;
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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("");
    scanf("%d", &jogadas);
    avaliacao_jogadas(tabuleiro, jogadas);
    return 0;
}