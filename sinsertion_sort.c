#include <stdio.h>
#include <stdlib.h>
int main (){
    int a[5];
    int i,j,temp;
    for (i=0 ; i<5 ; i++){
        printf("enter element =");
        scanf("%d",&a[i]);
    }
    for (i=1;i<5;i++){
        temp=a[i];
        j=i-1;
        while (j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        
    }
    printf ("sorted elements...\n");
    for (i=0;i<5;i++){
        
        printf ("%d\n", a[i]);
    }
}