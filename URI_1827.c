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
int **fill_centers(int n, int **matriz){
    int init_border = n/3; //isso aqui é o definição que a questão fornece para onde a ponta inicial da bordar ao redor do centro será  
    // será configurada, 1/3 da largura inicial
    int finish_border = n-1-(n/3); //com essa padrão eu subtraio a largura pela
    //ponta acima para pegar a ponta inversa e -1 porque o array começa com 0
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i >= init_border && i <= finish_border && j >= init_border && j <= finish_border){
                matriz[i][j] = 1;
            }
        }
    }
    matriz[n/2][n/2] = 4; //Ponto central
    return matriz;
}

int main(void){
    int n;
    scanf("%d", &n);
    if(n % 2 == 0){
        printf("A largura deve ser ímpar para aparecer o centro");
    }
    else{
        int **diagonals_matriz = fil_diagonals(n, fill_matrix(n));
        int **final_matriz = fill_centers(n, diagonals_matriz);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d", final_matriz[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}