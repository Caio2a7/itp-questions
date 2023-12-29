//Gradiente de Cores usando Números, ademais realizamos uma aposta com base na soma dos números do gradiente de cor
#include <stdio.h>

void calcular_aposta(int largura, int altura, int valor_inicial, char cor, int bandeira[altura][largura]) {
    char cores[] = {'G', 'Y', 'R'};
    int cor_gradiente = 0;
    int gradiente = valor_inicial + 1;
    int soma_aposta = 0;
    int valor_aposta = 0;
    int dif_aposta = 0;
    for (int i = 0; i < 3; i++) {
        if (cores[i] == cor) {
            cor_gradiente += valor_inicial + i + 1;
        }
    }
    
    for (int i = 0; i < largura; i++) {
        if (gradiente == cor_gradiente) {
            for (int j = 0; j < altura; j++) {
                bandeira[j][i] = gradiente;
                valor_aposta += gradiente;
            }
        }    
        if (i % (largura / 3) == (largura / 3) - 1) {
            gradiente++;
        }
    }
    printf("%d", valor_aposta);
}

int main() {
    int largura, valor_inicial;
    char cor;
    
    printf("");
    scanf("%d %d %c", &largura, &valor_inicial, &cor);
    
    if (largura % 3 != 0 || valor_inicial < 0 || (cor != 'G' && cor != 'Y' && cor != 'R')) {
        printf("Largura fora da proporção indicada, valor inicial negativo ou cor inválida. Refaça.\n");
    }
    else {
        int altura = (largura * 2) / 3;
        int bandeira[altura][largura];
        
        calcular_aposta(largura, altura, valor_inicial, cor, bandeira);
    }
    
    return 0;
}