#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
void insert(){
    int x;
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("enter value = ");
    scanf("%d", &x);
    ptr->data=x;
    
    if (head==NULL){
        ptr->link=NULL;
        head=ptr;
    }
    else{
        temp=head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=ptr;
        ptr->link=NULL;
    }
}

void display() {
    struct node *temp;
    temp = head;
    
    if (head == NULL) {
        printf("The list is empty\n");
    } 
    else {
        while (temp != NULL) {  // Change the condition to check for NULL directly
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");  // Print a newline for better formatting
    }
}

void first_delete(){
    struct node *temp;
    temp=head;
    if (head==NULL){
        printf("empty");
    }
    else {
        head=temp->link;
        free(temp);
    }
}
void last_delete() {
    struct node *temp = head;
    struct node *prev = NULL; 

    if (head == NULL) {
        printf("The list is empty\n");
        return; 
    }
    if (head->link == NULL) {
        free(head);  
        head = NULL; 
        printf("The last item deleted\n");
        return;  
    }
    while (temp->link != NULL) {
        prev = temp;      
        temp = temp->link; 
    }
    free(temp);          
    prev->link = NULL;   
    printf("The last item deleted\n");
}

void random_insert() {
    struct node *temp, *ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    int x, loc, i;

    printf("Enter data: ");
    scanf("%d", &x);
    temp->data = x;
    temp->link = NULL;  

    printf("Enter location (1 for head): ");
    scanf("%d", &loc);

    
    if (loc == 1) {
        temp->link = head;  // Point new node to the current head
        head = temp;        // Update head to the new node
        printf("Inserted at the head\n");
        return;
    }

    // Traverse to the node just before the specified location
    for (i = 1; i < loc - 1; i++) {
        if (ptr == NULL) {  // Check if we reached the end of the list
            printf("Location is out of bounds\n");
            free(temp);     // Free the allocated memory
            return;
        }
        ptr = ptr->link;
    }

    // If ptr is NULL after the loop, the location is out of bounds
    if (ptr == NULL) {
        printf("Location is out of bounds\n");
        free(temp);  // Free the allocated memory
        return;
    }

    // Insert the new node at the specified location
    temp->link = ptr->link;  // Link the new node to the next node
    ptr->link = temp;        // Link the previous node to the new node
    printf("Inserted at location %d\n", loc);
}
void count(){
    int count=0;
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->link;

    }
    printf("total =%d",count);
}

void search(){
    int x,i;
    printf("enter data = ");
    scanf("%d",&x);
    i=0;
    struct node *temp=head;
    while(temp->link!=NULL){
        if(temp->data==x){
            printf("item at %d",i);
        }
        else{
            temp=temp->link;
            i++;
        }
    }
}

void first_insert(){
    int x;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter data=");
    scanf("%d", &x);
    temp->data=x;
    temp->link=NULL;
    if(head==NULL){
        head=temp;
        temp->link=NULL;
    }
    else{
        temp->link=head;
        head=temp;
        return;
    }
}

void reverse(){
    struct node *pre,*current,*next;
    pre=0;
    current=head;
    next=NULL;
    if(head==NULL){
        printf("error");
    }
    else{
        while(current!=NULL){
            next=current->link;
            current->link=pre;
            pre=current;
            current=next;
        }
        
    }
    head=pre;

}
void main()
{
    int choice = 0;
    printf("1.insert\n2.display\n3.firstdelete\n4.lastdelete\n5.random_insert\n6.count\n");
    printf("7.search\n8.firstinsert\n9.reverse\n");
    

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("\n%d", &choice); // choice=1

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            first_delete();
            break;
        case 4:
            last_delete();
            break;
        case 5:
            random_insert();
            break;
        case 6:
            count();
            break;
        case 7:
            search();
            break;
        case 8:
            first_insert();
            break;
        case 9:
            reverse();
            break;  
        default:
            printf("Invalid Choice..");
        }

        
    }
}
