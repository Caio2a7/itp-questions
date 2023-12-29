#include <stdio.h>

void matriz_quadratica(int tamanho){
    int matriz[tamanho][tamanho];
    int centro = (tamanho)/2+0.5;
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(i == j){
                matriz[i][j] = 1;
            }
            else if(j == tamanho-i-1){
                matriz[i][j] = 2;
            }
            else{
                matriz[i][j] = 3;
            }
        }
    }
    if((tamanho)/2 % 2 == 0){
        matriz[centro][centro] = 2;
    }
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

}

int main(){
    while (1)
    {
        int tamanho;
        printf("");
        scanf("%d", &tamanho);
        if(tamanho == 0){
            break;
        }
        else {
            matriz_quadratica(tamanho);
        }
    }

    return 0;
}