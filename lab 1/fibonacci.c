#include <stdio.h>

void main() {

    int n, sum=0, a=0 , b=1;

    printf("Enter value for a : ");
    scanf("%d",&n);

    printf("Finonacci : ");
    for (int i = 1; i <n; i++)
    {
        printf("%d ", sum);
        a = b;
        b = sum;
        sum = a + b;
    }
    
    printf("%d", sum);
}