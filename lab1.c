#include<stdio.h>
#define n 5

int stack[5];
int top = -1;

void push() {
    int x;
    if (top == n - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter the number: ");
        scanf("%d", &x);
        stack[++top] = x;
        printf("Element pushed successfully\n");
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Popped element: %d\n", stack[top--]);
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3: {
                int val = peek();
                if (val != -1)
                    printf("Top element: %d\n", val);
                break;
            }

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
