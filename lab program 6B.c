#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


struct node* stackHead = NULL;
struct node* queueHead = NULL;



void push(int item)
{
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = item;
    ptr->next = stackHead;
    stackHead = ptr;

    printf("\nNode pushed to stack.");
}

void pop()
{
    struct node* ptr;

    if (stackHead == NULL) {
        printf("\nStack is empty.");
    }
    else {
        ptr = stackHead;
        stackHead = ptr->next;
        free(ptr);
        printf("\nNode popped from stack.");
    }
}

void displayStack()
{
    struct node* temp = stackHead;

    if (temp == NULL) {
        printf("\nStack is empty.");
        return;
    }

    printf("\nStack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}



void enqueue(int item)
{
    struct node* ptr;
    struct node* temp;

    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = item;
    ptr->next = NULL;

    if (queueHead == NULL) {
        queueHead = ptr;
        printf("\nNode inserted in queue.");
    } else {
        temp = queueHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        printf("\nNode inserted in queue.");
    }
}

void dequeue()
{
    struct node* ptr;

    if (queueHead == NULL) {
        printf("\nQueue is empty.");
    }
    else {
        ptr = queueHead;
        queueHead = ptr->next;
        free(ptr);
        printf("\nNode deleted from queue.");
    }
}

void displayQueue()
{
    struct node* temp = queueHead;

    if (temp == NULL) {
        printf("\nQueue is empty.");
        return;
    }

    printf("\nQueue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}



int main()
{
    int choice, value;

    while (1) {
        printf("\n\n===== STACK & QUEUE USING SINGLE LINKED LIST =====\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            displayStack();
            break;

        case 4:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 5:
            dequeue();
            break;

        case 6:
            displayQueue();
            break;

        case 7:
            printf("\nExiting program.\n");
            exit(0);

        default:
            printf("\nInvalid choice! Try again.");
        }
    }
    return 0;
}
