#include <stdio.h>

void main() {
    int n, ans=1;

    printf("Enter value for n : ");
    scanf("%d",&n);

    ans = factorial(n);
    
    printf("Factorial : %d", ans);
}

int factorial (int n) {
    if (n==1 || n==0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}