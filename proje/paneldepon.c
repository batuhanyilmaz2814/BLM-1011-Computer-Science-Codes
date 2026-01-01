#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char rastgele_olusum();
void yazdirma(char oyun_alani[20][20], int N, int M);

int main(){
    srand(time(NULL));
    int secim = 0;
    int i,j;
    int N,M;
    char oyun_alani[20][20];
    int oyun_modu;
    int D1X,D1Y,D2X,D2Y;
    int PX,PY;
    int ust_satir = -1;
    do{
    printf("Matris boyutlarını giriniz: \n");
    printf("Satir sayisi(En fazla 20): ");
    scanf("%d",&N);
    printf("Sutun sayisi(En fazla 20): ");
    scanf("%d",&M);

    if(N<2 || N>20 || M<2 || M>20){
        printf("Hatali matris boyutu girisi lutfen tekrar giris yapin.\n");}
    }while(N<2 || N>20 || M<2 || M>20);


    printf("Oyun modunu seciniz: \n 1-Oyun Modu \n 2-Kontrol Modu\n");
        scanf("%d",&oyun_modu);


    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            oyun_alani[i][j] = ' ';
        }
    }

    if(oyun_modu == 1){
        for(i=N-1; i>=(N/2); i--){
            for(j=0; j<M; j++){
                oyun_alani[i][j] = rastgele_olusum();
            }
        }

        while(secim != 3 && ust_satir != 0){
            ust_satir = N/2;

            yazdirma(oyun_alani,N,M);
            
            printf("Yer degisikligi icin 1,\n Patlatma icin 2 giriniz:\n");
            scanf("%d",&secim);
            if(secim == 1){
                printf("Yer degistirmek istediğiniz ilk nesnenin satir numarasini girin: ");
                scanf("%d",&D1X);
                printf("Yer degistirmek istediğiniz ilk nesnenin sutun numarasini girin: ");
                scanf("%d",&D1Y);
                printf("Yer degistirmek istediğiniz ikinci nesnenin satir numarasini girin: ");
                scanf("%d",&D2X);
                printf("Yer degistirmek istediğiniz ikinci nesnenin sutun numarasini girin: ");
                scanf("%d",&D2Y);

                char temp = oyun_alani[D1X-1][D1Y-1];
                oyun_alani[D1X-1][D1Y-1] = oyun_alani[D2X-1][D2Y-1];
                oyun_alani[D2X-1][D2Y-1] = temp;
            }else if(secim == 2){
                printf("Patlatmak istediginiz grubun sol ust kosesinin satir numarasini girin: ");
                scanf("%d",&PX);
                printf("Patlatmak istediginiz grubun sol ust kosesinin sutun numarasini girin: ");
                scanf("%d",&PY);

                char patlatma_karakter = oyun_alani[PX-1][PY-1];
                
                int yatay_say = 1;
                for(int j = PY-2; j >= 0 && oyun_alani[PX-1][j] == patlatma_karakter; j--){
                    yatay_say++;
                }
                for(int j = PY; j < M && oyun_alani[PX-1][j] == patlatma_karakter; j++){
                    yatay_say++;
                }
                
                int dikey_say = 1;
                for(int i = PX-2; i >= 0 && oyun_alani[i][PY-1] == patlatma_karakter; i--){
                    dikey_say++;
                }
                for(int i = PX; i < N && oyun_alani[i][PY-1] == patlatma_karakter; i++){
                    dikey_say++;
                }
                
                if(yatay_say >= 3 || dikey_say >= 3){
                    if(yatay_say >= dikey_say){
                        oyun_alani[PX-1][PY-1] = ' ';
                        for(int j = PY-2; j >= 0 && oyun_alani[PX-1][j] == patlatma_karakter; j--){
                            oyun_alani[PX-1][j] = ' ';
                        }
                        for(int j = PY; j < M && oyun_alani[PX-1][j] == patlatma_karakter; j++){
                            oyun_alani[PX-1][j] = ' ';
                        }
                    } else {
                        oyun_alani[PX-1][PY-1] = ' ';
                        for(int i = PX-2; i >= 0 && oyun_alani[i][PY-1] == patlatma_karakter; i--){
                            oyun_alani[i][PY-1] = ' ';
                        }
                        for(int i = PX; i < N && oyun_alani[i][PY-1] == patlatma_karakter; i++){
                            oyun_alani[i][PY-1] = ' ';
                        }
                    }
                    
                    for(int j = 0; j < M; j++){
                        for(int i = N - 1; i >= 0; i--){
                            if(oyun_alani[i][j] == ' '){
                                for(int k = i - 1; k >= 0; k--){
                                    if(oyun_alani[k][j] != ' '){
                                        oyun_alani[i][j] = oyun_alani[k][j];
                                        oyun_alani[k][j] = ' ';
                                    }
                                }
                            }
                        }
                    }
                } else {
                    printf("Bu koordinatta en az 3 aynı tas arka arka degil!\n");
                }
            }

            printf("\033[H\033[J");
            yazdirma(oyun_alani,N,M);
            ust_satir = ust_satir - 1;
        
        }

    }




    return 0;
}


char rastgele_olusum(){
    char karakter;
    int rastgele = rand() % 5;
    if(rastgele == 0){
        karakter = '0';
    }else if(rastgele == 1){
        karakter = '*';}
    else if(rastgele == 2){
        karakter = '/';
    }else if (rastgele == 3)
    {
        karakter = '+';
    }else if(rastgele == 4){
        karakter = '%';
    }

    return karakter;
}

void yazdirma(char oyun_alani[20][20], int N, int M){
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            printf("%c ",oyun_alani[i][j]);
        }
        printf("\n");
    }
}