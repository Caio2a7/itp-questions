#include <stdio.h>

int main(void){
    char pontos[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int distancia[7] = {0, 3, 1, 4, 1, 5, 9};

    char p, q;
    scanf("%c %c", &p, &q);
    int p_dist = 0;
    int q_dist = 0;
    for(int i = 0; i < 7; i++){
        if(p == pontos[i]){
            for(int j = 0; j <= i; j++){
                p_dist += distancia[j];
            }
        }
        if(q == pontos[i]){
            for(int j = 0; j <= i; j++){
                q_dist += distancia[j];
            }
        }
    }
    if(p_dist > q_dist){
        printf("%d", p_dist-q_dist);
    }
    else{
        printf("%d", q_dist-p_dist);
    }
    return 0;
}