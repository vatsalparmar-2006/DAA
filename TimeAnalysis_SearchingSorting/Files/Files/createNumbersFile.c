#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *fp;

    fp = fopen("best.txt", "w");
    for(int i=1; i<=100000; i++)
    {
        fprintf(fp, "%d ", i);
    }
    fclose(fp);

    fp = fopen("worst.txt", "w");
    for(int i=100000; i>=1; i--)
    {
        fprintf(fp, "%d ", i);
    }
    fclose(fp);

    fp = fopen("average.txt", "w");
    for(int i=1; i<=100000; i++)
    {
        fprintf(fp, "%d ", rand() % 100000);
    }
    fclose(fp);
}