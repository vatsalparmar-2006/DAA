#include <stdio.h>

void main() {
    int n, digit=0, rem;

    printf("Enter value for n : ");
    scanf("%d",&n);

    while (n!=0)
    {
        rem %= 10;
        digit ++;
        n /= 10;
    }
    
    printf("Digits : %d", digit);
}