#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Em loop o usuário irá fornecendo o valor a, b, c dos lados de um possível triângulo, meu código terá que analisar
//Se os lados podem formar um triangulo, se é equilátero, isósceles, escaleno e se é retângulo
//No final tendo que armazenar esses dados em um array e printá-los
//printf("%d %d %d", lados[tam-1].a, lados[tam-1].b, lados[tam-1].c);
typedef struct {
    int a, b, c;
    char *tipo;
    char *retangulo;
} Triangulo;

int is_triangle(Triangulo *lados, int tam){
    int req = 0;
    lados[tam-1].a < lados[tam-1].b + lados[tam-1].c? req++ : 0;
    lados[tam-1].b < lados[tam-1].a + lados[tam-1].c? req++ : 0;
    lados[tam-1].c < lados[tam-1].a + lados[tam-1].b? req++ : 0;
    if(req == 3){
        return 1;
    }
    else{
        return 0;
    }
}
int is_equilatero(Triangulo *lados, int tam){
    if(lados[tam-1].a == lados[tam-1].b && lados[tam-1].b == lados[tam-1].c &&
    lados[tam-1].a == lados[tam-1].c){
        return 1;
    }
    else{
        return 0;
    }
}
int is_isosceles(Triangulo *lados, int tam){
    if(lados[tam-1].a == lados[tam-1].b && lados[tam-1].a != lados[tam-1].c ||
    lados[tam-1].a == lados[tam-1].c && lados[tam-1].b != lados[tam-1].c ||
    lados[tam-1].b == lados[tam-1].c && lados[tam-1].a != lados[tam-1].b){
        return 1;
    }
    else{
        return 0;
    }
}
int is_escaleno(Triangulo *lados, int tam){
    if(lados[tam-1].a != lados[tam-1].b && lados[tam-1].b != lados[tam-1].c &&
    lados[tam-1].a != lados[tam-1].c){
        return 1;
    }
    else{
        return 0;
    }
}
int is_retangulo(Triangulo *lados, int tam){
    int req = 0;
    pow(lados[tam-1].a, 2) + pow(lados[tam-1].b, 2) == pow(lados[tam-1].c, 2)? req++ : 0;
    pow(lados[tam-1].b, 2) + pow(lados[tam-1].a, 2) == pow(lados[tam-1].c, 2)? req++ : 0;
    pow(lados[tam-1].c, 2) + pow(lados[tam-1].a, 2) == pow(lados[tam-1].b, 2)? req++ : 0;
    if(req >= 1){
        return 1;
    }
    else{
        return 0;
    }
}


int main(void){
    int tam = 0; 
    Triangulo *lados = NULL; 
    
    do {
        tam++; 
        lados = realloc(lados, sizeof(Triangulo) * tam);  
        
        if (lados == NULL) {
            printf("Erro ao realocar memória.\n");
            return 1;
        }
        
        printf("--Digite abaixo os respectivos lados a b c do triângulo | Se digitar 0 0 0 o programa encerra--\n");
        scanf("%d %d %d", &lados[tam - 1].a, &lados[tam - 1].b, &lados[tam - 1].c);
        getchar();
        if(is_triangle(lados, tam) == 1){
            printf("TRI");
            if(is_equilatero(lados, tam) == 1){ printf("EQUI"); }
            else if(is_isosceles(lados, tam) == 1){ printf("ISOS");  }
            else if(is_escaleno(lados, tam) == 1){ printf("ESCALENO");  }
            else if(is_retangulo(lados, tam) == 1){ printf("RETA");  }
        }
        else{
            printf("INVALIDO");
        }
    } while(lados[tam - 1].a != 0 || lados[tam - 1].b != 0 || lados[tam - 1].c != 0);

    free(lados); 

    return 0;
}
