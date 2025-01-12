//using 2 stacks//

#include <stdlib.h>
#include <stdio.h>
#define N 5
int s1[N], s2[N];
int top1=-1,top2=-1;
int count=0;

void enqueue(int x){
    push1(x);
    count++;
}
void push1(int data){
    if (top1==N-1){
        printf("overflow");   
    }
    else{
        top1++;
        s1[top1]=data;
    }
}
void push2(int data){
    if (top2==N-1){
        printf("overflow");   
    }
    else{
        top2++;
        s2[top2]=data;
    }
}
void dequeue(){
    int i,a,b;
    if(top1==-1 && top2==-1){
        printf("queue is empty");
    }
    else {
        for (i=0;i<count;i++){
            a=pop1();
            push2(a);
        }
        b=pop2();
    }
    printf("dequeued element is %d",b);
    count--;
    for (i=0;i<count;i++){
        a=pop2();
        push1(a);
    }
}
int pop1() {
    int a;
    if (top1 == -1) {
        printf("stack1 is empty\n");
        return -1; // Return an error value
    }
    else{
        return s1[top1--];
    }
}

int pop2() {
    int b;
    if (top2 == -1) {
        printf("stack2 is empty\n");
        return -1; // Return an error value
    }
    else{
        return s2[top2--];
    }
    
}

void display(){
    int i;
    for (i=0;i<=top1;i++){
        printf("%d ",s1[i]);
    }

}
int main (){
    int choice,x;
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    
    while (1){
        printf ("\nenter your choice=");
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

