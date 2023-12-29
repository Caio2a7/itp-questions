//Essa função irá utilizar o algoritmo de Euclides para achar o mdc, utilizando os seguintes lemas:
//lema 1: se r é inteiro positivo então mdc(r, 0) = r
//lema 2: seja a, b inteiros ambos não nulos, tendo q e r inteiros com 0 < q <= b, tal que a = b*q+r, então 
//mdc(a,b) = mdc(b, r)
//Agora sobre o passo a passo em mdc(a, b)....
//Função recursiva que começa apartir de b | a e monta a igualdade algoritmo da divisão a = b*q+r
//apartir disso irá pegar o resto(r) e fará r | b, ou seja o r se torna b e se torna a
//apartir disso irá gerar outro resto(r) pelo algoritmo e repitirá o mesmo procedimento
//válido ressaltar que sempre teremos os quocientes na equação também
//O algoritmo vai repetindo até o 'b' como quociente 0 se tornar zero, uma forma do tipo:
// x = a*q + 0 -- antes do final, lembre sempre do de b | a para r | b
// a = b*0+ 1 //linha de chegada, mdc é o a
// para o caso dos números serem múltiplos ele ira retornar
//resto 0 na primeira recursão e o mdc será o quociente dessa divisão / equação do algoritmo
#include <stdio.h>

int mdc_calc(int x, int y){
    if(y == 0){ //perceba que aqui o 'b' seria 
        return(x); //aqui estou passando o 'a' da divisão que teve seu 'b' 0
    }
    else{
        return mdc_calc(y, x%y); //retomando o texto acima usando o r como y e b como x (r | b)
    }
}

void calc_mdc_mmc(int x, int y, int *mdc, int *mmc){
    *mdc = mdc_calc(x, y);
    *mmc = (x*y)/ *mdc;
}

int main(void){
    int x, y, mdc, mmc;
    scanf("%d %d", &x, &y);
    calc_mdc_mmc(x, y, &mdc, &mmc);
    printf("MDC: %d MMC: %d", mdc, mmc);
    return 0;
}