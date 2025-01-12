#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insert() {
    int x;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode; 
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode; 
        newnode->prev = temp; 
    }
}


void display_count() {
    struct node *temp;
    int count = 0;
    temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        printf("List elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data); 
            count++;
            temp = temp->next;
        }
        printf("\nTotal nodes = %d\n", count); 
    }
}

int main() {
    int choice;
    printf("1. Insert\n2. Display Count\n3. Exit\n");
    while (1) {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                display_count();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}