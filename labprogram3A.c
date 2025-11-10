#include <stdio.h>
#define SIZE 50  

int queue[SIZE];
int front = -1, rear = -1;


void insert(int x) {
    if(rear == SIZE - 1) { 
        printf("Queue Overflow! Cannot insert %d\n", x);
        return;
    }
    if(front == -1) {  
        front = 0;
    }
    queue[++rear] = x;
    printf("%d inserted into queue.\n", x);
}


void delete() {
    if(front == -1 || front > rear) { 
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }
    int deleted = queue[front++];
    printf("%d deleted from queue.\n", deleted);

    
    if(front > rear) {
        front = rear = -1;
    }
}


void display() {
    if(front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


int main() {
    int choice, value;

    while(1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
