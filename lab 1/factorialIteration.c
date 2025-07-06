#include <stdio.h>

void main() {
    int n, ans=1;

    printf("Enter value for n : ");
    scanf("%d",&n);

    for (int i = n; i >= 1; i--)
    {
        ans *= i;
    }
    
    printf("Factorial : %d", ans);
}