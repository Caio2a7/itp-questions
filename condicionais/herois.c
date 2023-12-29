#include <stdio.h>

int main(){
    int heroi;
    int monstro;
    int quantidade_herois;
    printf("");
    scanf("%d %d %d", &quantidade_herois, &heroi, &monstro);
    
    if (heroi == monstro && quantidade_herois == 3){
        printf("Heróis vencerão!");
    }
    else if(heroi > monstro && quantidade_herois == 1){
        printf("Heróis vencerão!");
    }
    else if(heroi == 5 && quantidade_herois == 1 && monstro == 5){
        printf("Heróis vencerão!");
    }
    else {
        printf("Melhor chamar Saitama!");
    }
}