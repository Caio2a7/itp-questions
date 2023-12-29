#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **regex(char **emails, int index){
    for(int i = 0; i < index; i++){
        char *dominio = strtok(emails[i], "@");
        dominio = strtok(NULL, ".");
        emails[i] = strdup(dominio);
    }
    return emails;
}
void impressao(char **emails, int index){
    printf("Domínios: \n");
    for(int i = 0; i < index; i++){
        printf("%s\n", emails[i]);
    }
}

int main(void) {
    char **emails = NULL;
    int index = 0;
    int fim = 1;
    while (fim){
        emails = (char **)realloc(emails, sizeof(char *) * (index + 1));
        emails[index] = (char *)malloc(sizeof(char) * 100);


        scanf(" %s", emails[index]);
        if(strcmp(emails[index], "FIM") == 0){
            fim = 0;
        }
        index++;
    } 

    impressao(regex(emails, index), index);

    for (int i = 0; i < index; i++) {
        free(emails[i]);
    }
    free(emails);

    return 0;
}