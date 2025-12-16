#include <stdio.h>

int main(){
    int N,i,eleman;
    int dizi[100];
    printf("Eleman sayisini girin: ");
    scanf("%d", &N);

    int bas = 0;
    int son = N-1;
    int orta = N/2;
    int isFound = 0;

    for(i=0; i<N; i++){
        printf("%d. elemani giriniz: ", i+1);
        scanf("%d", &dizi[i]);
    }

    printf("Aranan degeri giriniz: ");
    scanf("%d", &eleman);

    while((isFound==0)&&(bas<=son)){
        if(dizi[orta]==eleman){
            isFound = 1;
        }
        else{
            if(eleman<dizi[orta]){
                son = orta -1;

            }else{
                bas = orta +1;

            }
            orta = (bas + son)/2;
        }
    }


    if(isFound==1){
        printf("%d. eleman", orta+1);

        }else{
            printf("Boyle bir eleman dizide yoktur.");
        }
    return 0;
}