#include <stdio.h>

int main(){
    int sayi;

    printf("Lütfenn bir doğal sayı giriniz: ");
    scanf("%d", &sayi);

    int uzunluk = 0;
    int maxUzunluk = 0;
    int onceki = 0;


    while(sayi>0){

        if (sayi > onceki){
            uzunluk+=1;

        }
        else{
            if(uzunluk > maxUzunluk){
                maxUzunluk = uzunluk;
            }
            uzunluk = 1;
        }

        onceki = sayi;

        printf("Bir sayı giriniz (bitirmek için sıfır): ");
        scanf("%d", &sayi);
    }

    if(uzunluk > maxUzunluk){
        maxUzunluk = uzunluk;
    }

    printf("Girilen sayılardaki en uzun artan seri uzunluğu: %d\n", maxUzunluk);

    return 0;
}