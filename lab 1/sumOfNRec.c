#include <stdio.h>

int sumOfN (int n) {
    if(n==0){
        return 0;
    }
    else {
        return n + sumOfN(n-1);
    }
}

void main() {
    int n, sum=0, ans;

    printf("Enter value for n : ");
    scanf("%d",&n);

    ans = sumOfN(n);

    printf("Sum : %d", ans);
}