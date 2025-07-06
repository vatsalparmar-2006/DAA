#include <stdio.h>

void main() {
    int a,b, ans=1;

    printf("Enter value for a : ");
    scanf("%d",&a);

    printf("Enter value for b : ");
    scanf("%d",&b);

    for (int i = 1; i <=b; i++)
    {
        ans = ans*a;
    }
    
    printf("Answer : %d", ans);
}