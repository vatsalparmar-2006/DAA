#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int n, int searchElement)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == searchElement)
        {
            return mid;
        }
        else if (arr[mid] > searchElement)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

void performSearch(const char filePath[], int size, const char fileLabel[]) {
    FILE *fp = fopen(filePath, "r");

    int arr[100000];  // max size assumed

    for (int i = 0; i < size; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    int cases[3] = {0, size / 2, size - 1};  
    const char *caseLabels[3] = {"Best", "Average", "Worst"};

    printf("\n--- %s ---\n", fileLabel);
    for (int i = 0; i < 3; i++) {
        int searchElement = arr[cases[i]];
        
        clock_t start = clock();
        int result = binarySearch(arr, size, searchElement);
        clock_t end = clock();

        double cpuTime = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%s Case:\n", caseLabels[i]);
        if (result != -1) {
            printf("Element %d found at index %d\n", searchElement, result);
        } else {
            printf("Element %d not found\n", searchElement);
        }
        printf("Time Taken: %lf seconds\n\n", cpuTime);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Binary Search File Menu ---\n");
        printf("1. hundred.txt (100 values)\n");
        printf("2. thousand.txt (1,000 values)\n");
        printf("3. ten_thousand.txt (10,000 values)\n");
        printf("4. hundred_thousand.txt (100,000 values)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            performSearch("../Files/hundread.txt", 100, "File: hundred.txt");
            break;
        case 2:
            performSearch("../Files/thousand.txt", 1000, "File: thousand.txt");
            break;
        case 3:
            performSearch("../Files/ten_thousand.txt", 10000, "File: ten_thousand.txt");
            break;
        case 4:
            performSearch("../Files/hundread_thousand.txt", 100000, "File: hundred_thousand.txt");
            break;
        case 5:
            printf("Exiting...\n");
            return 0; 
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
