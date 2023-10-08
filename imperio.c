//Usando técnicas de descriptografia KPA Ataque do texto plano 
//Descriptografando a cifra de Vigeneré
//C - mensegem criptografada
//KP - knowplaintext ou mensagem conhecida, na 2ª guerra os alemão sempre saudavam heil hilter no final da mensagem
//K - key ou a chave de criptografia/descriptografia
//P - mensagem original
//S - caracters permitidos na cifra
#include <stdio.h>
#include <string.h>
int decifrar_cifra(char C[], const char KP[], int K[]){
    const char S[]= {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                     'A', 'B', 'C', 'D', 'E', 'F','G', 'H', 'I', 'J',
                     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};
    int tamanhos[3] = {strlen(C)-1, strlen(S), strlen(KP)}; //vetor com o tamanho do objeto criptografado, dicionário e knowplaintext
    int KP_posicoes[100]; 
    //Aqui definirei a posição de cada caracter do Knowplaintext no dicionário fornecido e atribuirei em um vetor
    for(int i = 0; i < tamanhos[2]; i++){
        for(int j = 0; j < tamanhos[1]; j++){
            if(KP[i] == S[j]){
                KP_posicoes[i] = j;
                break;
            }
        }
    }
    int posicao[tamanhos[0]];
    for(int i = 0; i < tamanhos[0]; i++){
        for(int j = 0; j < tamanhos[1]; j++){
            if(C[i] == S[j]){
                posicao[i] = j;
                break; 
            }
        }
    }
    for(int i = 0; i < tamanhos[0]; i++){
        for(int j = 0; j < tamanhos[0]; j++){
            if(i+j >= tamanhos[0]){
                K[i] = posicao[j-i]-KP_posicoes[j];
                printf("FOi if\n");
            }
            else{
                K[i] = posicao[i+j]-KP_posicoes[j];
            }
            printf("CHAVE: %d - %d\n", i, K[i]);
        }
        printf("\n");
    }    
}


int descriptografia_da_mensagem(){}


int main(){
    const char KP[100] = "QUE A FORCA ESTEJA COM VOCE";
    char C[100];
    int K[25];
    fgets(C, 99, stdin);

    decifrar_cifra(C, KP, K);

    return 0;
}