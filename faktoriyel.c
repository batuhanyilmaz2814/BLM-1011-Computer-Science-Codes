#include <stdio.h>

int faktoriyel(int sayi);

int main(){

    int sayi;

    do
    {
        printf("Pozitif bir sayi giriniz: ");
        scanf("%d", &sayi);
        if (sayi < 0){
            printf("Negatif sayıların faktoriyeli alınamaz. Lütfen pozitif bir sayı giriniz.\n");
            continue;
        }
    } while (sayi < 0);

    printf("%d sayısının faktoriyeli: %d\n",sayi, faktoriyel(sayi));
    
    


    return 0;
}


int faktoriyel(int sayi){

    int faktoriyel = 1;


    for(int i = 2; i<= sayi; i++){
        faktoriyel = i*faktoriyel;
    }

    return faktoriyel;
}