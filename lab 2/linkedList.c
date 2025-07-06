#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// insert at first
void insertAtFirst(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// insert at last
void insertAtLast(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// insert at any position 
void insertAtPosition(int value, int pos) {
    if (pos <= 1) {
        insertAtFirst(value);
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// remove from first
void removeFromFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// remove from last
void removeFromLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// remove by value
void removeByValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Value not found.\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// change
void changeValue(int oldValue, int newValue) {
    struct Node* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("Value %d not found in list.\n", oldValue);
    }
}

// display
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos, oldVal, newVal;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Position\n");
        printf("4. Remove from First\n");
        printf("5. Remove from Last\n");
        printf("6. Remove by Value\n");
        printf("7. Change Value\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtFirst(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtLast(value);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position (1-based): ");
            scanf("%d", &pos);
            insertAtPosition(value, pos);
            break;
        case 4:
            removeFromFirst();
            break;
        case 5:
            removeFromLast();
            break;
        case 6:
            printf("Enter value to remove: ");
            scanf("%d", &value);
            removeByValue(value);
            break;
        case 7:
            printf("Enter value to change: ");
            scanf("%d", &oldVal);
            printf("Enter new value: ");
            scanf("%d", &newVal);
            changeValue(oldVal, newVal);
            break;
        case 8:
            display();
            break;
        case 9:
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
