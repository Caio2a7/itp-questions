#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LENGTH 100
const char vogais[10] = {'a', 'e', 'i', 'o', 'u'};

char *string_reverse(char risada[], int vogal_contador) {
    static char reversed_risada[MAX_STR_LENGTH];
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