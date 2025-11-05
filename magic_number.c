#include <stdio.h>

int main(){
    int n;
    int sayi;

    printf("Enter a number: ");
    scanf("%d", &n);

    int maxMacigCount = 0;
    int bestRow = 0;

    for(int i = 1; i<=n; i++){
        int macigCount = 0;
       
        for(int j=1; j<=n; j++){
            int sum = 0;

            printf("Enter number for row %d, column %d: ", i, j);
            scanf("%d", &sayi);
            
            while(sayi > 0 || sum > 9){
                if(sayi == 0){
                    sayi = sum;
                    sum = 0;

                }
                
                sum = sum + (sayi%10);
                sayi = sayi / 10;
            }

            if(sum == 1){
                macigCount += 1;
            }

        }

        if (macigCount > maxMacigCount) {
            maxMacigCount = macigCount;
            bestRow = i;
        }


    }


    printf("En iyi satır: %d\n Sihirli sayı sayısı: %d\n", bestRow, maxMacigCount);

    return 0;
}


