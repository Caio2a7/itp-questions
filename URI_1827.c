//Square matrix ou matriz quadŕatica nxn marcação de diagonais elemento central e arredores do central
//0 - Preenchimento básico da matriz
//1 - Arredores do centro
//2 - diagonal principal
//3 - diagonal secundária
//4 - centro
#include <stdio.h>
#include <stdlib.h>

int **fill_matrix(int n){
    int **matriz;
    matriz = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++){
        matriz[i] = (int *)malloc(sizeof(int) * n);
    }
    return matriz;
}
int **fil_diagonals(int n, int **matriz){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                matriz[i][j] = 2;
            }
            else if(i == n-1-j && j == n-1-i || j == n-1-i && i == n-1-j){
                //padrão para as posições da diagonal secundária, todos as coordena
                //das dessa diagonal segue o padrão de ser a largura-1-i ou j
                matriz[i][j] = 3;
            }
        }
    }
    return matriz;
}

int main(void){
    int n;
    scanf("%d", &n);
    if(n % 2 == 0){
        printf("A largura deve ser ímpar para aparecer o centro");
    }
    else{
        int **matriz = fill_matrix(n);
        fil_diagonals(n, matriz);
    }

    return 0;
}