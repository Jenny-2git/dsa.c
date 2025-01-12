#include <stdio.h>
#include <stdlib.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else if ((rear + 1) % N == front) {
        printf("Queue is full\n");
    } else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d ", queue[rear]);
    }
    printf("\n");
}

void peek() {
    if (front == -1 && rear == -1) { // Added check for empty queue
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
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
 