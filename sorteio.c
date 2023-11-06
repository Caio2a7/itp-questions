#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct{
    char *caracter;
} string;

int main(){
    string *participantes;
    do{
        participantes = (char **)malloc(sizeof(char *) * 2);
        participantes[1].caracter = (char *)malloc(sizeof(char) * 100);
        scanf("%s", participantes[0]);
        printf("%s", participantes[0]);
    } while(participantes[0] != 'acabou');

    return 0;
}
