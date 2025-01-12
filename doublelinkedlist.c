#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *tail;
void create(){
    struct node *newnode;
    newnode=(struct node*)malloc (sizeof (struct node));
    printf ("enter data =");
    scanf("%d", &newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if (head==0){
        head=tail=newnode;
    }
    else {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void insertbeg(){
    struct node *newnode, *temp;
    newnode=(struct node*)malloc (sizeof (struct node));
    printf ("enter data =");
    scanf("%d", &newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if (head==0){
        head=tail=newnode;
    }
    else{
        temp=head;
        head=newnode;
        newnode->next=temp;
        temp->prev=newnode;
    }
}
void insertend (){
    struct node *newnode, *temp;
    newnode=(struct node*)malloc (sizeof (struct node));
    printf ("enter data =");
    scanf("%d", &newnode->data);
    newnode->prev=0;
    newnode->next=0;
    temp=head;
    if (head==0){
        head=tail=newnode;
    }
    else {
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=tail;
    }
}
void position(){
    int pos,i,length=0;
    struct node *newnode, *temp;temp=head;
    newnode=(struct node*)malloc (sizeof (struct node));
    printf ("enter data =");
    scanf("%d", &newnode->data);
    newnode->prev=0;
    newnode->next=0;
    printf ("enter position =");
    scanf("%d", &pos);

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    if (pos<1 || pos> length+1){
        printf ("invalid");
        free (newnode);
    }
    else if (pos==1){
        insertbeg();
        return;
    }
    for (i=0;i<pos-1 ;i++){
        temp=temp->next;
    }
    newnode->next = temp->next; 
    newnode->prev=temp;
    temp->next=newnode;
    temp->next->next->prev=newnode;
    
}
void display(){
    struct node *temp;temp=head;
    while (temp != NULL) {
        printf ("%d\n",temp->data);
        temp = temp->next;
    }
}
int main (){
    int choice;
    printf ("1.create\n2.insertbeg\n3.insertend\n4.positon\n5.display\n6.exit\n");
    while (1){
        scanf("%d\n ", &choice);
        switch (choice){
            
            case 1:
                create();
                break;
            case 2:
                insertbeg();
                break;
            case 3:
                insertend();
                break;
            case 4:
                position();
                
            case 6:
                exit(0);
            case 5:
                display();
                break;
        }
    }
}