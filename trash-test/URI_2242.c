#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LENGTH 100
const char vogais[10] = {'a', 'e', 'i', 'o', 'u'};

char *string_reverse(char risada[], int vogal_contador) {
    static char reversed_risada[MAX_STR_LENGTH];
    /*afeta como essa variável é armazenada na memória e como ela mantém seu valor entre as chamadas da função.
Quando uma variável local é declarada como static dentro de uma função em C, ela mantém seu valor entre as chamadas 
da função. Isso significa que, após a primeira chamada da função string_reverse(), a variável reversed_risada mantém 
seu valor entre as chamadas subsequentes.

Como a variável reversed_risada está declarada como um array de caracteres dentro da função string_reverse, 
ela é alocada na memória estática. Isso significa que, em vez de ser alocada na pilha de execução como uma variável 
automática (que é alocada e desalocada cada vez que a função é chamada), a memória para reversed_risada é alocada na 
memória estática. Isso permite que o valor da variável persista entre as chamadas da função.

Quando você retorna reversed_risada no final da função string_reverse, o que você está retornando é um ponteiro 
para o primeiro elemento do array reversed_risada. Na prática, isso se comporta como um ponteiro para a string 
que foi construída na função.*/
    int contador = 0;
    for (int i = vogal_contador; i >= 0; i--) {
        reversed_risada[contador] = risada[i]; 
        contador++;
    }
    reversed_risada[contador] = '\0'; 

    printf("\n%s", reversed_risada);
    return reversed_risada; 
}


int main(void){
    char risada[MAX_STR_LENGTH];
    char c;
    int string_contador = 0;
    int vogal_contador = 0;
    while((c = getchar()) != '\n' && c != EOF && string_contador < MAX_STR_LENGTH-1){
        for(int i = 0; i < 5; i++){
            if(c == vogais[i]){
                risada[vogal_contador] = c;
                vogal_contador++;
            }
        }
        string_contador++;
    }
    vogal_contador--; //ultimo tamhanho indica vazio na string
    risada[string_contador] = '\0';
    printf("\n%s", risada);
    string_reverse(risada, vogal_contador);

    return 0;
}