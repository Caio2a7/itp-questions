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
    return reversed_risada; 
}
char cmp_string(char reversed_risada[], char risada[], int vogal_contador){
    for(int i = 0; i < vogal_contador; i++){
        if(risada[i] != reversed_risada[i]){
            return 'N';
        }
    }
    return 'S';
}

int main(void){
    char risada_vogais[MAX_STR_LENGTH];
    char c;
    int string_contador = 0;
    int vogal_contador = 0;
    while((c = getchar()) != '\n' && c != EOF && string_contador < MAX_STR_LENGTH-1){
        for(int i = 0; i < 5; i++){
            if(c == vogais[i]){
                risada_vogais[vogal_contador] = c;
                vogal_contador++;
            }
        }
        string_contador++;
    }
    vogal_contador--; //ultimo tamhanho indica vazio na string
    risada_vogais[string_contador] = '\0';
    char *reversed_string = string_reverse(risada_vogais, vogal_contador);
    char string_cmp = cmp_string(reversed_string, risada_vogais, vogal_contador);
    printf("O reverso das vogais da risada é igual? %c", string_cmp);
    return 0;
}
