#include <stdio.h>
#include<stdlib.h>

void search(int a[], int total){
    int search,i;
    printf("enter ele to search = ");
    scanf("%d", &search);
    for(i=0;i<total;i++){
        if(a[i]==search){
            printf("at position = %d",i+1);
        }
        else{
            continue;
        }
    }
}
void delete(int a[],int total){
    int i,n, delpos;
    printf("enter position to delete = ");
    scanf("%d", &delpos);
    for (i = delpos-1; i < total ; i++) {
        a[i] = a[i + 1];
    }
    total--;
    for (i=0;i<total;i++){
        printf("%d ", a[i]);
    }
}
void newele(int a[],int total){
    int i, new,n;
    printf("enter new element = ");
    scanf("%d", &new);
    a[total]=new;
    total++;

    for (i=0;i<total;i++){
        printf("%d ", a[i]);
    }


}
void replace( int a[],int total){
    int pos,i,num;
    printf("enter position= ");
    scanf("%d", &pos);
    printf("enter num= ");
    scanf("%d", &num);
    if(pos>total){
        printf("invald pos");
    }
    else{
        a[pos-1]=num;
    }
    for (i=0;i<total;i++){
        printf("%d ", a[i]);
    }
}

int main (){
    int a[50],total,i,ch;
    printf("enter total = ");
    scanf("%d", &total);
    for (i=0;i<total;i++){
        scanf("%d", &a[i]);
    }
    for (i=0;i<total;i++){
        printf("%d ", a[i]);
    }

    printf("\n1.new element\n2.delete element\n3.search element\n4.replace\n5.break\n");
    while(1){
        printf("\nenter choice = ");
        scanf("%d", &ch);
        switch(ch){
            case 1:newele(a,total);
                break;
            case 2:delete(a,total);
                break;
            case 3:search(a,total);
                break;
            case 4:replace(a,total);
                break;
            case 5:
                break;
        }
    }


    
    
   
}