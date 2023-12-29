#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *nome;
    int idade;
    char sexo;
} Pessoa;

Pessoa create() {
    Pessoa pessoa_dados;
    pessoa_dados.nome = (char *)malloc(sizeof(char) * 100);
    printf("Digite o nome: ");
    scanf(" %99[^\n]", pessoa_dados.nome);
    printf("Digite a idade: ");
    scanf(" %d", &pessoa_dados.idade);
    printf("Digite o sexo (M/F): ");
    scanf(" %c", &pessoa_dados.sexo);
    return pessoa_dados;
}

void inserir(Pessoa *pessoas, int tamanho) {
    pessoas[tamanho - 1] = create();
}

void deletar(Pessoa *pessoas, int *tamanho) {
    Pessoa pessoa_delete = create();
    int encontrado = 0;

    for (int i = 0; i < *tamanho; i++) {
        if (strcmp(pessoa_delete.nome, pessoas[i].nome) == 0 &&
            pessoa_delete.idade == pessoas[i].idade &&
            pessoa_delete.sexo == pessoas[i].sexo) {
            encontrado = 1;
            for (int j = i; j < *tamanho - 1; j++) {
                pessoas[j] = pessoas[j + 1];
            }
            (*tamanho)--; 
            pessoas = (Pessoa *)realloc(pessoas, sizeof(Pessoa) * (*tamanho));
        }
    }

    if (encontrado) {
        printf("Pessoa deletada\n");
    } else {
        printf("Pessoa não encontrada\n");
    }
}

int main() {
    char option;
    int tamanho = 0;
    Pessoa *pessoas = NULL;

    do {
        printf("Escolha uma opção (i para inserir, d para deletar, p para parar): ");
        scanf(" %c", &option);

        switch (option) {
            case 'i':
                tamanho++;
                pessoas = (Pessoa *)realloc(pessoas, sizeof(Pessoa) * tamanho);
                inserir(pessoas, tamanho);
                break;
            case 'd':
                deletar(pessoas, &tamanho);
                break;
            case 'p':
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (option != 'p');

    for (int i = 0; i < tamanho; i++) {
        printf("%s %d %c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
        free(pessoas[i].nome);
    }

    free(pessoas);

    return 0;
}
