#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// Usar tratamento de erros, while , for, condicionais, e bibliotecas
// Farei um sistema de gerenciamento de autenticação, ou seja, ele terá um banco de dados(arquivo.txt) com senhas e nomes
//dos usuários, caso a pessoa for fazer o login ele irá comparar os dados, caso for para se cadastrar ele irá adicionar os 
//dados no banco e dados
//Ademais ele possuirá funções para encriptar e decriptar
char *login_senha(){ 
    char *senha = NULL;
    size_t len = 0; 
    printf("Senha: "); 
    getline(&senha, &len, stdin);
    return senha;}
char *login_user(){
    char *usuario = NULL;
    size_t len = 0; 
    printf("Usuário: "); 
    getline(&usuario, &len, stdin); 
    return usuario;}
void criptografador(char *string, const char *alfabeto){
    int len = strlen(string);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < strlen(alfabeto); j++) {
            if (string[i] == alfabeto[j]) {
                string[i] = alfabeto[j+2];
                break;
            }
        }
    }
}
void descriptografador(char *string, const char *alfabeto){
    int len = strlen(string);
    
    for (int i = 0; i < len; i++){
        for (int j = 0; i < strlen(alfabeto); j++) {
            if (string[i] == alfabeto[j]){
                string[i] = alfabeto[j-2];
                break;
            }
        }
    }
}
int main(){
    char *nova_senha = login_senha();
    char *novo_usuario = login_user();
    printf("%s  %s \n", nova_senha, novo_usuario);
    const char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
    char objeto1[100] = &nova_senha;
    char objeto2[100] = *novo_usuario;
    criptografador(objeto1, alfabeto);
    printf("Seu objeto criptografado: %s\n", objeto1);
    descriptografador(objeto1, alfabeto);
    printf("Seu objeto descriptografado: %s\n", objeto1);
    criptografador(objeto2, alfabeto);
    printf("Seu objeto criptografado: %s\n", objeto2);
    descriptografador(objeto2, alfabeto);
    printf("Seu objeto descriptografado: %s\n", objeto2);

}
