#include <stdio.h>
#define SIZE 5  

int queue[SIZE];
int front = -1, rear = -1;


int isFull() {
    return (front == (rear + 1) % SIZE);
}


int isEmpty() {
    return (front == -1);
}


void insert(int x) {
    if(isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", x);
        return;
    }
    if(isEmpty()) {  
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;  
    }
    queue[rear] = x;
    printf("%d inserted into the circular queue.\n", x);
}


void delete() {
    if(isEmpty()) {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }
    int deleted = queue[front];
    if(front == rear) {  
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;  
    }
    printf("%d deleted from the circular queue.\n", deleted);
}


void display() {
    if(isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = front;
    while(1) {
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}


int main() {
    int choice, value;

    while(1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the integer to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
