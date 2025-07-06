#include <stdio.h>

int digitCount(int n) {
    if (n < 10) {
        return 1;
    } else {
        return 1 + digitCount(n / 10);
    }
}

void main() {
    int n, digit=0, ans;

    printf("Enter value for n : ");
    scanf("%d",&n);
    
    if (n<0)
    {
        n = -n;       
    }
    
    ans = digitCount(n);

    printf("Digits : %d", ans);
}