#include <stdio.h>

void main() {
    int n, sum=0;

    printf("Enter value for a : ");
    scanf("%d",&n);

    for (int i = 1; i <=n; i++)
    {
        sum += i;
    }
    
    printf("Answer : %d", sum);
}