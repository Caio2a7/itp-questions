//Usando técnicas de descriptografia KPA Ataque do texto plano 
//Descriptografando a cifra de Vigeneré
//C - mensegem criptografada
//KP - knowplaintext ou mensagem conhecida, na 2ª guerra os alemão sempre saudavam heil hilter no final da mensagem
//K - key ou a chave de criptografia/descriptografia
//P - mensagem original
//S - caracters permitidos na cifra
#include <stdio.h>
#include <string.h>
char S[]= {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                     'A', 'B', 'C', 'D', 'E', 'F','G', 'H', 'I', 'J',
                     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};
int *decifrar_cifra(char C[200], const char KP[], int K[]){
    int KP_posicoes[200]; 
    //Aqui definirei a posição de cada caracter do Knowplaintext no dicionário fornecido e atribuirei em um vetor
    for(int i = 0; i < strlen(KP); i++){
        for(int j = 0; j < strlen(S); j++){
            if(KP[i] == S[j]){
                KP_posicoes[i] = j;
                break;
            }
        }
    }
    int posicao[strlen(C)-1];
    for(int i = 0; i < strlen(C)-1; i++){
        for(int j = 0; j < strlen(S); j++){
            if(C[i] == S[j]){
                posicao[i] = j;
                break; 
            }
        }
    }
    int controlador = 0; //usarei essa variável para evitar stackoverflow e realizar um controle do array
    int correcao;
    for(int i = 0; i < strlen(C)-1; i++){
        for(int j = 0; j < strlen(KP); j++){
            if(i+j >= strlen(C)-1){
                K[j] = posicao[controlador]-KP_posicoes[j];
                controlador++;
            }
            else{
                if(posicao[i+j] < KP_posicoes[j]){
                    correcao = KP_posicoes[j]-(posicao[i+j]+1);
                    K[j] = KP_posicoes[j]-correcao;
                }
                else{
                    K[j] = posicao[i+j]-KP_posicoes[j];
                }
            }
        }
        controlador = 0;
        int padrao_cifra = 0;
        for(int h = 0; h < strlen(KP); h++){
            if(K[h] == K[h+4]){
                padrao_cifra++;
                if(controlador >= 4){
                    controlador = 0;
                }
                K[controlador] = K[h+4];
                controlador++;
            }
            else{
                padrao_cifra = 0;
            }
            if(padrao_cifra >= 16){
                int armazenamento;
                if(K[0] > K[1]){
                    return K;
                }
                else{ 
                    for(int m = 0; m < 3; m++){
                    if(K[m+1] < K[m]){
                        armazenamento = K[m+1];
                        K[m+1] = K[m];
                        K[m] = armazenamento;
                        }
                    }
                    return K;
                }
            }
        }
    }
    return 0;    
}


int *descriptografia_da_mensagem(char C[], int cifra[]){
    int controlador = 0;
    for(int i = 0; i < strlen(C)-1; i++){
        for(int j = 0; j < strlen(S); j++){
            if(C[i] == S[j]){
                if(j-cifra[controlador] < 0){
                    C[i] = S[39+(j-cifra[controlador]+1)];
                }
                else{
                    C[i] = S[j- cifra[controlador]];
                }
                controlador++;
                break; 
            }
        }
        if(controlador == 4){ controlador = 0; }
    }
    return C;
}


int main(){
    const char KP[200] = "QUE A FORCA ESTEJA COM VOCE";
    char C[200];
    int K[50];
    fgets(C, 200, stdin);
    int *arm = decifrar_cifra(C, KP, K);
    int cifra[3];
    if (arm != NULL) {
        for (int i = 0; i < 4; i++) {
            cifra[i] = arm[i];
            printf("%d", cifra[i]);
        }
        printf("\n");
        char *mensagem = descriptografia_da_mensagem(C, cifra);
        for(int i = 0; i < strlen(C)-1; i++){
            printf("%c", mensagem[i]);
        }
    }  
    else {
        printf("Mensagem nao e da Resistencia!");
    }
    return 0;
}