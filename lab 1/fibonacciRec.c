#include <stdio.h>

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void main() {
    int n;

    printf("Enter value for n : ");
    scanf("%d",&n);

    printf("Finonacci : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }
}