#include <stdio.h>

int main(){
    int n;
    int kontrol;

    printf("Dizinin boyutunu girin: ");
    scanf("%d", &n);

    int dizi[n];

    for(int i = 0; i<= n-1; i++){
        printf("Dizinin %d. elemanını girin: ", i);
        scanf("%d", &dizi[i]);
    }

    kontrol = 0;

    for(int j =0; j<=n-1; j++){
        for(int k = 0; k<=n-1; k++){
            if(dizi[j] == dizi[k] && j != k){
                kontrol = 1;
                k = n; /* Döngüden çıkması için (break görmedik).*/
                j = n;
            }

        }
    }

    if(kontrol == 1){
        printf("Unique dizi değildir.\n");
    }else{
        printf("Unique dizidir.\n");
    }


    return 0;
}