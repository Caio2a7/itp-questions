void calculo_sensor(int N, int M, int sensor[][M]){
    int sabre_de_luz = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(sensor[i][j] == 42){
                for(int k = -1; k <= 1; k++){
                    if(sensor[i+k][j+k] == 7){
                        sabre_de_luz++;
                    }
                    if(sensor[i][j+k] == 7){
                        sabre_de_luz++;
                    }
                    if(sensor[i+k][j] == 7){
                        sabre_de_luz++;
                    }
                    if(sensor[i+k][j-k] == 7){
                        sabre_de_luz++;
                    }
                }
                if(sabre_de_luz == 8){
                    printf("Sabre de luz encontrado! \nCoordenadas: [%d, %d]", i+1, j+1);
                    break;
                }
                sabre_de_luz = 0;
            }
        }
    }
}

int main(){
    int N, M; //dimensões N x M de detecção do sensor
    printf("");
    scanf("%d %d", &N, &M);
    int sensor[N][M];
    for(int i = 0; i < N; i++){
        printf("");
        for(int j = 0; j < M; j++){
            scanf("%d", &sensor[i][j]);
        }
    }
    calculo_sensor(N, M, sensor);
    return 0;
}
