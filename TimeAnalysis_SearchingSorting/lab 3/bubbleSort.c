#include<stdio.h>
#include<time.h>
#include<string.h>

void bubbleSort(int arr[], int n)
{
    int exchanged = 0 ;

    for (int i = 0; i < n-1; i++)
    {
        exchanged = 0;
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                exchanged = 1;
           }
        }
    }

    if(exchanged == 0)
    {
        printf("Already sorted.\n");
    }
}

int main()
{
    int choice, size;
    char filename[50];
    FILE *fp;

    printf("Choose case:\n");
    printf("1. Best Case\n");
    printf("2. Average Case\n");
    printf("3. Worst Case\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        sprintf(filename, "../Files/best.txt");
        break;
    case 2:
        sprintf(filename, "../Files/average.txt");
        break;
    case 3:
        sprintf(filename, "../Files/worst.txt");
        break;
    default:
        printf("Invalid choice!\n");
        return 1;
    }

    printf("Enter number of elements (max 100000): ");
    scanf("%d", &size);

    if (size < 1 || size > 100000)
    {
        printf("Size must be between 1 and 100000.\n");
        return 1;
    }

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    int arr[100000]; // Max size

    for (int i = 0; i < size; i++)
    {
        if (fscanf(fp, "%d", &arr[i]) != 1)
        {
            printf("Error reading data from file. File might not contain enough numbers.\n");
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);

    clock_t start = clock();
    bubbleSort(arr, size);
    clock_t end = clock();

    double cpuTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%s (%d): %.2fs\n", strrchr(filename, '/') ? strrchr(filename, '/') + 1 : filename, size, cpuTime);

    return 0;
}
