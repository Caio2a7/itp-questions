#include <stdio.h>

int main() {
    int temperatura;
    char escala;
    printf("");
    scanf("%d %c", &temperatura, &escala);

    if (escala == 'C') {
        printf("Celsius: %.2lf\n", (double) temperatura);
        printf("Fahrenheit: %.2lf\n", (double) (temperatura * 1.8) + 32);
        printf("Kelvin: %.2lf\n", (double) temperatura - 273.15);
    }
    else if (escala == 'K') {
        printf("Celsius: %.2lf\n", (double) temperatura - 273.15);
        printf("Fahrenheit: %.2lf\n", (double) (temperatura - 273.15) * 1.8 + 32);
        printf("Kelvin: %.2lf\n", (double) temperatura);
    }
    else if (escala == 'F') {
        printf("Celsius: %.2lf\n", (double) (temperatura - 32) / 1.8);
        printf("Fahrenheit: %.2lf\n", (double) temperatura);
        printf("Kelvin: %.2lf\n", (double) (5.0 / 9.0) * (temperatura - 32) + 273.15);
    }
    else {
        printf("Escala não reconhecida.\n");
    }

    return 0;
}