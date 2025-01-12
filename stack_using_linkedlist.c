#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *top = NULL; // Initialize top to NULL

void push() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) { 
        printf("Memory allocation failed\n");
        return;
    }
    
    printf ("enter data = ");
    scanf("%d",&newnode->data);
    if (top==NULL){
        top=newnode;
    }
    else{
        newnode->link=top;
        top=newnode;
    }
 
   
}

void pop() {
    struct node *temp;
    temp = top;
    if (top == NULL) { // Check if the stack is empty
        printf("Stack is empty\n");
    } else {
        printf("Popped element is %d\n", top->data);
        top = top->link;
        free(temp); // Free the memory of the popped node
    }
}

void display() {
    struct node *temp;
    temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void peek() {
    // if (top == NULL) { // Check if the stack is empty
    //     printf("Stack is empty\n");
    // } else {
    //     printf("Top element is %d\n", top->data);
    // }
    printf("Top element is %d\n", top->data);
}

int main() {
    int choice, x;
    printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push(); 
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5: // Corrected to use a colon
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
