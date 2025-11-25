#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;


struct node* create_node(int val)
{
    struct node *new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}


void insert_beg(int val)
{
    struct node *new_node = create_node(val);

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void delete_val(int val)
{
    if (head == NULL)
    {
        printf("Empty list!\n");
        return;
    }

    struct node *temp = head;


    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Value not found!\n");
        return;
    }


    if (temp == head)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }


    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        free(temp);
        return;
    }


    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

void display()
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    int choice, val, pos;

    while (1)
    {
        printf("\n1. Insert at Beginning\n");
        printf("2. Delete Node by Value\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_beg(val);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete_val(val);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

