#include <stdio.h>
#include<stdlib.h>
int main(){
    int a[10],n,i,b[10];
    printf("enter length = ");
    scanf("%d", &n);
    for (i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    countingsort(a,n,b);
    for (i=0;i<n;i++){
        printf("%d", a[i]);
    }
}
void countingsort(int a[], int n, int b[]){
    int i,k;
    int count=0;
    for(i=0;i<n;i++){
        ++count[a[i]];
    }
    for(i=1;i<=k;i++){
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--){
        b[--count[a[i]]]=a[i];
    }
}
