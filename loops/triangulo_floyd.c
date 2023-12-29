#include <stdio.h>

int main() {
    int n;

    printf("");
    scanf("%d", &n);
    if (n == 0 || n < 0){
        printf("Você entrou com %d, tente de novo na próxima", n);
    }
    else {
        int num = 1;  // Número a ser impresso no triângulo
    
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%2d ", num);  // Usando "%2d" para garantir espaço para dois dígitos
                num++;
            }
            printf("\n");
        }
    }

    return 0;
}