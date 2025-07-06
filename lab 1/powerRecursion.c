#include <stdio.h>

int powerRecursion (int a, int b) {
    if (b==0) {
        return 1;
    }
    else {
        return a * powerRecursion(a, b-1);
    }
}

void main() {
    int a, b, ans;

    printf("Enter value for a : ");
    scanf("%d",&a);

    printf("Enter value for b : ");
    scanf("%d",&b);
    
    ans = powerRecursion(a,b);

    printf("Answer : %d", ans);
}