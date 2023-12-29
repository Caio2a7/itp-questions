#include <stdio.h>

int main(){
    int tamanho = 10;
    int array_numeros[tamanho];
    for(int i = 0; i < tamanho; i++){
        int numero;
            printf("");
            scanf("%d", &numero);
            if(numero == 0){
                array_numeros[i] = 1;
            }
            else{
                array_numeros[i] = numero;
            }
        }
    for(int i = 0; i < tamanho; i++){
        printf("X[%d]: %d\n", i+1, array_numeros[i]);
    }
    return 0;
}