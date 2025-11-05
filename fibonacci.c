#include <stdio.h>

int main(){

    int n, s1, s2;

    printf("Kaç tane fibonacci sayısı istiyorsunuz? ");
    scanf("%d", &n);

    s1 = 0;
    s2 = 1;

    for(int i = 1; i <= n; i++){
        
        for(int j=1; j <= i; j++){
            printf("%d ", s1);
            s2 = s1 + s2;
            s1 = s2 - s1;
        }

        printf("\n");
    }


    return 0;
}