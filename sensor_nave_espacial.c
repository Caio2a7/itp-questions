void calculo_sensor(){}

int main(){
    int N, M; //dimensões N x M de detecção do sensor
    printf("");
    scanf("%d %d");
    int sensor[N][M];
    for(int i = 0; i < N; i++){
        printf("");
        for(int j = 0; j < M; j++){
            scanf("%d ", &sensor[i][j]);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%d ", sensor[i][j]);
        }
        printf("\n");
    }
    return 0;
}