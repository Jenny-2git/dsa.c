#include <stdlib.h>
#include <stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int data){
    if (rear==N-1){
        printf ("overflow");
    }
    else if (front==-1 && rear==-1){
        front =rear=0;
        queue[rear]=data;
        
    }
    else{
        rear++;
        queue[rear]=data;
    }
}

void dequeue(){
    if  (front==-1 && rear==-1){
        printf("empty");
    }
    // else if(front==rear){
    //     front=rear=-1;
    // }
    else{
        printf ("%d",queue[front]);
        front++;
        
    }
}

void display()
{
    if  (front==-1 && rear==-1){
        printf("empty");
    }
    else {
        for(int i=front; i<=rear; i++){
            printf ("%d\n", queue[i]);
        }
    }
}

void peek(){
    if  (front==-1 && rear==-1){
        printf("empty");
    }
    else {
        printf ("%d\n", queue[front]);

    }
}

int main (){
    int data,choice;
    printf("1. enqueue\n");
    printf("2.dequeue\n");
    printf("3.print queue\n");
    printf("4.peek\n");
    printf("5.exit\n");
    while(1){
        printf("enter your choice = ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("enter data =");
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
                exit (0);
            default:
                printf("invalid choice\n");

        }
    }
    return 0;
}

