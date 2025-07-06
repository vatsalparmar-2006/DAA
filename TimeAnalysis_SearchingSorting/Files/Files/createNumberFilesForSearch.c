#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *fp;
    
    fp = fopen("hundread.txt", "w");
    for (int i = 1; i < 101; i++)
    {
        fprintf(fp, "%d ", i);
    }
    fclose(fp);

    fp = fopen("thousand.txt", "w");
    for (int i = 1; i < 1001; i++)
    {
        fprintf(fp, "%d ", i);
    }
    fclose(fp);

    fp = fopen("ten_thousand.txt", "w");
    for (int i = 1; i < 10001; i++)
    {
        fprintf(fp, "%d ", i);
    }
    fclose(fp);

    fp = fopen("hundread_thousand.txt", "w");
    for (int i = 1; i < 100001; i++)
    {
        fprintf(fp, "%d ", i);
    }
    fclose(fp);
}