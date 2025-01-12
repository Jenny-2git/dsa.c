#include <stdio.h>
#include <stdlib.h>
#define N 5
struct node {
    int data;
    struct node *link;
};

struct node * front = 0;
struct node *rear =0;

void enqueue(int x) {
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=NULL;

    if (front == 0 && rear == 0) {
        front = rear = newnode;
        rear->link=front;
    } else {
        rear->link=newnode;
        rear=newnode;
        newnode->link=front;
    }
}

void dequeue() {
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=front;
    if (front == 0 && rear == 0){
        printf("empty");
    }
    else if (front==rear){
        front=rear=0;
    }
    else{
        printf("deququed element %d, queue[front]");
        front=front->link;
        rear->link=front;
        free(temp);
    }
}

void display() {
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=front;
    if (front == 0 && rear == 0) {
        printf("Queue is empty\n");
    } else {
        while (temp->link!=front) {
            printf("%d ", temp->data);
            temp=temp->link;
            
        }
        printf("%d ", rear->data);
    }
    printf("\n");
}

void peek() {
    if (front == 0 && rear == 0) { // Added check for empty queue
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

int main() {
    int data, choice;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
 