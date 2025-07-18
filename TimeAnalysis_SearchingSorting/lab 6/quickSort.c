#include <stdio.h>
#include <time.h>
#include <string.h>

int quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int i = low;
        int j = high;
        int pivot = arr[low];

        while (i < j)
        {

            while (i < high && arr[i] <= pivot)
            {
                i++;
            }
            while (j > low &&  arr[j] > pivot)
            {
                j--;
            }

            if (i < j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        arr[low] = arr[j];
        arr[j] = pivot;

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

void generateBestCase(int arr[], int i, int j)
{
    if (i < j)
    {
        int mid = (i + j) / 2;

        int temp = arr[i];
        arr[i] = arr[mid];
        arr[mid] = temp;

        generateBestCase(arr, i + 1, mid);
        generateBestCase(arr, mid + 1, j);
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

    if (choice == 1)
    {
        generateBestCase(arr, 0, size - 1);
    }
    
    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    clock_t end = clock();

    double cpuTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%s (%d): %.2fs\n", strrchr(filename, '/') ? strrchr(filename, '/') + 1 : filename, size, cpuTime);

    return 0;
}