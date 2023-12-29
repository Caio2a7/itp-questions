#include <stdio.h>
#include <string.h>

int main(void){
    char palavra[30] = "FALA@OLA.OI.ALOU";
    char *token = strtok(palavra, "@.");
    printf("%s", token);

    return 0;
}