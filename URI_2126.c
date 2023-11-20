#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 100

void subsequence_finder(const char *subsequence, const char *sequence) {
    const char *substring = sequence;
    int contador = 0;
    while ((substring = strstr(substring, subsequence)) != NULL) {
        printf("\nPos: %ld", substring - sequence);
        substring++;
        contador++;
    }
    printf("\nQtd: %d vezes", contador);
}

int main(void) {
    char subsequence[MAX_STR_LENGTH], sequence[MAX_STR_LENGTH];
    scanf("%s", subsequence);
    getchar(); 
    scanf("%s", sequence);

    subsequence_finder(subsequence, sequence);
    return 0;
}
