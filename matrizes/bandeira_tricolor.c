/*Neste código utilizaremos de matrizes para definir um gradiente de cores com números inteiros
simbolizando a cor do gradiente, nesse caso o gradiente é de uma bandeira tricolor;
Ademais, o usuário selecionará uma das cores e a cor selecionada será usada para somar todos
seus números no gradiente para somar o valor de uma aposta.
*/
#include <stdio.h>
//Faremos todos os cáculos e operações em uma função
// Entrada do usuário: largura valor_inicial cor
// O valor inicial serve para definir os números do gradiente
void calcular_aposta(int largura, int altura, int valor_inicial, char cor, int bandeira[altura][largura]) {
    char cores[] = {'G', 'Y', 'R'};  // nome arbitrário das cores tricolor
    int cor_gradiente = 0;           // será utilizado para definir qual o número inteiro do gradiente corresponde a cor
    int gradiente = valor_inicial + 1;     // trabalharemos com os números inteiros do gradiente aqui
    int soma_aposta = 0;    
    int valor_aposta = 0;
    int dif_aposta = 0;
    // Verificamos a cor escolhida no array de cores e definimos a cor_gradiente com base no valor_inicial
    for (int i = 0; i < 3; i++) {
        if (cores[i] == cor) {
            cor_gradiente += valor_inicial + i + 1;
        }
    }
    //Aqui criamos o gradiente iterando os dados para a bandeira, além de aplicarmos condicinais para a aposta
    for (int i = 0; i < largura; i++) {
        if (gradiente == cor_gradiente) {  //verificando se o valor do gradiente corresponde ao da cor
            for (int j = 0; j < altura; j++) {
                bandeira[j][i] = gradiente;
                valor_aposta += gradiente;  // Aqui fazemos a soma para a aposta
            }
        }
        else {
            for (int j = 0; j < altura; j++) {
                bandeira[j][i] = gradiente;
                soma_aposta += gradiente;
            }
        }
        //fazemos uma verificação para aumentar o valor do gradiente
        if (i % (largura / 3) == (largura / 3) - 1) {   //lembre-se que cada cor da bandeira deve ter um número
            gradiente++;
        }
    }
    //printamos
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            printf("%d ", bandeira[i][j]);
        }
        printf("\n");
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
