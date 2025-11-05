#include <stdio.h>

int main(){
    int number;
    int k;

    printf("Please enter a natural number: ");
    scanf("%d", &number);

    printf("Please enter the rotation factor k: ");
    scanf("%d", &k);

    int length = 0;
    int factor = 1;
    int temp = number;

    while(number > 0){
        length +=1;
        factor = factor * 10;
        number = number / 10;
    }

    factor = factor / 10;
    k = k % length; // Ensure k is within the length of the number

    for(int i = 1; i <= k; i++){
        int lastDigit = temp % 10;
        temp = temp / 10;
        temp = lastDigit * (factor + temp);
    }

    printf("The number after %d rotations is: %d\n", k, temp);
}