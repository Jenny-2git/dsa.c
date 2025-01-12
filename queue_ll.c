#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=NULL;
    if (front==0 && rear==0){
        front=rear=newnode;
    }
    else{
        rear->link=newnode;
        rear=newnode;
    }
}

void dequeue(){
    struct node*temp;

    if (front==0 && rear==0){
        printf ("empty");
    }
    else{
        temp=front;
        front=front->link;
        free(temp);
    }

}

void display(){
    struct node *temp;
    if (front==0 && rear==0){
        printf ("empty");
    }
    else {
        temp=front;
        while (temp!=0){
            printf ("%d\n",temp->data);
            temp=temp->link;
        }
    }
}

int main (){
    int choice,x;
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    
    while (1){
        printf ("enter your choice=");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("enter data =");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
}