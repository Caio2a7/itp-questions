#include <stdio.h>
#include <string.h>

int main() {
    char modalidades[50];  
    int atletas[3] = {0};  
    int equipes;

    printf("");
    scanf("%d", &equipes);

    for (int j = 0; j < equipes; j++) {
        printf("");
        scanf(" %[^\n]", modalidades);

        for (int i = 0; i < strlen(modalidades); i++) {
            char modalidade = modalidades[i];
            if (modalidade == 'S') {
                atletas[0]++;
            } else if (modalidade == 'C') {
                atletas[1]++;
            } else if (modalidade == 'L') {
                atletas[2]++;
            }
        }
    }
    printf("%d %d %d %d", atletas[1], atletas[0], atletas[2], atletas[0]+atletas[1]+atletas[2]);
    return 0;
}
