#include <stdio.h>
#include <stdlib.h>
void delete(int a[][],int ){

}

int main(){
    int a[3][3],i,j,num,r,c;
    printf("enter rows = ");
    scanf("%d", &r);
    printf("enter column = ");
    scanf("%d", &c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("enter number = ");
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<r;i++){
        printf("\n");
        for(j=0;j<c;j++){
            printf("%d ",a[i][j]);
        }
    }
}