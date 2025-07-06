#include <stdio.h>
#define SIZE 100

// struct  Stack
// {
//     int top;
//     int arr[SIZE];
// };

int top = -1;
int arr[SIZE];

// push
void push(int data)
{
    if (top == SIZE - 1)
    {
        printf("Overflow.");
    }
    else
    {
        arr[++top] = data;
    }
}

// pop(remove top element)
int pop()
{
    if (top == -1)
    {
        printf("Underflow.");
        return 0;
    }
    else
    {
        return arr[top--];
    }
}

// display
void display()
{
    if (top == -1)
    {
        printf("Empty.");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}

// peep(return top element)
int peep(int index)
{
    if (top - index + 1 < 0)
    {
        printf("Not");
        return 0;
    }
    else
    {
        return arr[top - index + 1];
    }
}

// change
void change(int index, int value)
{
    if (top - index + 1 < 0)
    {
        printf("Invalid Index");
    }
    else
    {
        arr[index] = value;
    }
}

int main()
{
    int choice, data, index, value, result;

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peep\n");
        printf("5. Change\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push : ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            result = pop();
            printf("Popped : %d\n", result);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Enter index from top to peep : ");
            scanf("%d", &index);
            result = peep(index);
            printf("Peeped  : %d\n", result);
            break;
        case 5:
            printf("Enter index from top to change : ");
            scanf("%d", &index);
            printf("Enter new value : ");
            scanf("%d", &value);
            change(index, value);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
