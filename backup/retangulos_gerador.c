//É o seguinte meu patrão, para compreender  esse problema entenda o seguinte
//você recebe 4 valores de entrada para os dados de 1 único retângulo
//(x1, y1) - Primeiro ponto
//(x2, y2) - Segundo ponto
//para você poder comparar esse retângulo com outro segue a seguinte lógica cartesiana
//se o primeiro ponto do retângulo 1 < primeiro ponto retângulo 2
//e se segundo ponto do retângulo 1 > segundo ponto retângulo 2
//então retângulo 1 maior que o 2
//pois se o primeiro ponto é menor (sla 0 < 10) e o segundo é maior (sla 30 > 20) então a área do primeiro
//retângulo vai ser muito maior que a dor segundo
//capiche?
#include <stdio.h>

void comparacoes(float retangulo_tela[], float retangulo[]) {
    if (retangulo_tela[0] == retangulo[0] && retangulo_tela[1] == retangulo[1] &&
        retangulo_tela[2] == retangulo[2] && retangulo_tela[3] == retangulo[3]) {
        printf("Nao posso afirmar!");
    }
    else if (retangulo[0] >= retangulo_tela[0] && retangulo[1] >= retangulo_tela[1] &&
        retangulo[2] <= retangulo_tela[2] && retangulo[3] <= retangulo_tela[3]) {
        printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n",
            retangulo_tela[0], retangulo_tela[1], retangulo_tela[2], retangulo_tela[3],
            retangulo[0], retangulo[1], retangulo[2], retangulo[3]);
        }
    else if (retangulo_tela[0] >= retangulo[0] && retangulo_tela[1] >= retangulo[1] &&
        retangulo_tela[2] <= retangulo[2] && retangulo_tela[3] <= retangulo[3]) {
        printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n",
            retangulo[0], retangulo[1], retangulo[2], retangulo[3],
            retangulo_tela[0], retangulo_tela[1], retangulo_tela[2], retangulo_tela[3]);
    }
    else {
        printf("Nao posso afirmar!\n");
        }
}

int main() {
    float retangulo_tela[4];
    float retangulo[4];
    printf("");
    scanf("%f %f %f %f", &retangulo_tela[0], &retangulo_tela[1], &retangulo_tela[2], &retangulo_tela[3]);
    while (1) {
        int finalizar = 0;
        printf("");
        scanf("%f %f %f %f", &retangulo[0], &retangulo[1], &retangulo[2], &retangulo[3]);
        for (int i = 0; i < 4; i++) {
            if (retangulo[i] == 0) {
                finalizar++;
            }
            else {
                break;
            }
        }
        if (finalizar == 4) {
            break;
        }
        else {
            comparacoes(retangulo_tela, retangulo);
        }
    }
    return 0;
}