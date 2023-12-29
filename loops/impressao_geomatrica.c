#include <stdio.h>

int main() {
    int linhas;
    char caracter[20];

    printf("");
    scanf("%d %c", &linhas, &caracter);
    
    for (int i = 1; i < linhas; i++) {
        for (int j = 1; j < linhas; j++) {
            if (j == i || j == linhas-i) {
                printf("%c", caracter[0]);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
