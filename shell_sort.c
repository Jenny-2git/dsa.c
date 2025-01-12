#include <stdio.h>
#include <stdlib.h>
int main(){
    int a[20],i,n,gap;
    printf("enter length = ");
    scanf("%d", &n);
    for (i=0;i<n;i++){
        printf("enter element = ");
        scanf("%d",&a[i]);
    }
    shellsort(a,n,gap);
    printf("sorted array...");
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
void shellsort(int a[],int n,int gap){
    int i,j;
    for(gap=n/2;gap>=1; gap /= 2){
        for(j=gap;j<n;j++){
            for(i=j-gap;i>=0;i -= gap){
                if(a[j]>a[i]){
                    break;
                }
                else{
                    swap(&a[j],&a[i]);
                }
            }
        }
    }
}
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

