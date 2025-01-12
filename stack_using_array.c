
#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack [N];
int top=-1;

void push (){
    int x;
    printf("enter data=");
    scanf("%d",& x);
    if (top==N-1)
    {
        printf ("overflow");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

void pop(){
    int item;
    if (top==-1)
    {
        printf("underflow");
    }
    else
    {
        item=stack[top];
        top--;
    }
    printf("%d\n",item);
}

//topmost element
void peek(){
    if (top==-1)
    {
        printf("overflow");
    }
    else
    {
        printf("%d\n",stack[top]);
    }

}

void display(){
    int i;
    for (i=top;i>=0;i--){
        printf("\n%d\n", stack [i]);
    }
}

int main (){

    int choice,x ;
    printf("1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
    
    while (1){
        printf ("enter your choice=");
        scanf("%d", &choice);
        switch (choice){
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
            case 5:
                exit(0);
        }
    }
}