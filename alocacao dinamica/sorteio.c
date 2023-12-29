#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
//TIPO STRING, usando um ponteiro apontando para um char, voce aloca memoria
//dinamicamente nele usando malloc para definir qual é o tamanho limite do seu tipo
//string
typedef struct{
    char *caracter;
} string;


void sorteio(string *participantes, int semente, int incrementador) {
    srand(semente);
    int *indexes = (int *)malloc(sizeof(int) * incrementador); // Array para manter controle dos índices usados
    memset(indexes, 0, sizeof(int) * incrementador); // Inicializa todos como zero

    for (int i = 0; i < incrementador; i++) {
        int index;
        do {
            index = rand() % incrementador; // Gera um índice aleatório
        } while (indexes[index]); // Verifica se já foi usado, pois se o indice ainda não foi usado será 0 e o loop acaba

        indexes[index] = 1; // Marca o índice como usado para no próximo loop ele ficar rodando até alcançar um zero

        printf("%s", participantes[index].caracter);
    }

    free(indexes); // Libera o array de controle de índices
}

int main() {
    string *participantes = NULL; //aqui eu criei um ponteiro apontando para esse tipo string
    int incrementador = 0;

    do {
        //aqui eu aloca memória dinamicamente para esse tipo almejando criar um 
        //vetor de strings dinamico
        participantes = (string *)realloc(participantes, sizeof(string) * (incrementador + 1));
        participantes[incrementador].caracter = (char *)malloc(sizeof(char) * 100);
        fgets(participantes[incrementador].caracter, 100, stdin);
        incrementador++;
    } while (strcmp(participantes[incrementador - 1].caracter, "acabou\n") != 0);

    int semente;
    scanf("%d", &semente);

    sorteio(participantes, semente, incrementador - 1);

    for (int i = 0; i < incrementador; i++) {
        free(participantes[i].caracter);
    }
    free(participantes);
    return 0;
}
