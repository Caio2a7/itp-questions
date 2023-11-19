#include <stdio.h>
#include <stdlib.h>
//diagonalização de matrizes quadráticas
//Ou seja, irá tornar aparente as diagonais da matriz, a principal e inversa
int** matriz_aloc(int n){
    int **matriz;
    matriz = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++){
        matriz[i] = (int *)malloc(sizeof(int) * n);
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            matriz[i][j] = 3;
        }
    }
    return matriz;
}
int** matriz_diagonals(int** matriz, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                matriz[i][j] = 1;
            }
            else if(i == (n-1)-j){
                matriz[i][j] = 2;
            }
        }
    }
    return matriz;
}
void print_matriz(int **matriz, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int n;
    printf("Type 0 to stop\n");
    while(scanf("%d", &n) != 0){
        int **matriz = matriz_diagonals(matriz_aloc(n), n);
        print_matriz(matriz, n);
    }

    return 0;
}