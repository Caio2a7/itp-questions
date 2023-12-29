#include <stdio.h>
int main(){
    int codigo;
    int dinheiro;
    int cardapio[] = {{12, 23}, 31, 28, 15};
    printf("");
    scanf("%d %d", &codigo, &dinheiro);

    if (dinheiro == cardapio[codigo-1]){
        printf("Deu certim!");
        return 1;
    }
    else if(dinheiro > cardapio[codigo-1]) {
        int troco = dinheiro-cardapio[codigo-1];
        printf("Troco = %d reais", troco);
        return 1;
    }
    else if(dinheiro < cardapio[codigo-1]) {
        int faltam = cardapio[codigo-1]-dinheiro;
        printf("Saldo insuficiente! Faltam %d reais", faltam);
        return 1;
    }
    return 0;
}