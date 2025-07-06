#include <stdio.h>
#define SIZE 100

int front = -1;
int rear = -1;
int arr[SIZE];

// enqueue
void enqueue(int data)
{
    if (rear == SIZE - 1)
    {
        printf("Overflow.");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        arr[++rear] = data;
    }
}

// dequeue
int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow.");
        return 0;
    }
    else
    {
        return arr[front++];
    }
}

// display
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Empty.");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}

// peek
int peek()
{
    if (front == -1 || front > rear)
    {
        printf("Empty.");
        return 0;
    }
    else
    {
        return arr[front];
    }
}

// change
void change(int index, int value)
{
    if (index <= 0 || front + index - 1 > rear)
    {
        printf("Invalid Index");
    }
    else
    {
        arr[front + index - 1] = value;
    }
}

int main()
{
    int choice, data, index, value, result;

    while (1)
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Change\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue : ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            result = dequeue();
            printf("Dequeued : %d\n", result);
            break;
        case 3:
            display();
            break;
        case 4:
            result = peek();
            printf("Front : %d\n", result);
            break;
        case 5:
            printf("Enter index from front to change : ");
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
