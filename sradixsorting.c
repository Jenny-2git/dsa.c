#include<stdio.h>

void display (int array[], int size);
void radixsorting(int array[], int size);

int main(){
    int a[10],n,i;
    printf ("length = ");
    scanf("%d", &n);
    for (i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    radixsorting(a,n);
    printf("sorted...\n");
    display (a,n);

}

int getmaxlem(int arr[], int n)
{
    int i;
    int max_ele = arr[0];
    for (i=1; i<n; i++)
    {
        max_ele = arr[i]; 
    }
    return max_ele;
}

void countingsort(int arr[], int size,int place)
{
    int i;
    int output[size+ 1];
    int max = (arr[0] / place) % 10;

    for (i=1 ;i <= size ; i++){
        if (((arr[i] / place) % 10) > max)
            max = arr[i];
    }


    int count[max +1];  

    for(i=0; i < max ; ++i)
        count[i]=0;
    for(i=0 ; i< size ; i++)
        count [(arr[i] / place )% 10 ]++;
    for(i= 1 ; i< 10; i++)
        count[i]+= count[i-1];
    for(i= size-1 ; i >=0 ; i--)
    {
        output[count[(arr[i] / place ) % 10] - 1]= arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for(i=0; i< size ; i++)
        arr[i] = output[i];
}


void radixsorting( int array[],int size)
{
    int place;
    int max  = getmaxlem (array , size );
    for (place =1; max/place > 0; place *= 10)
        countingsort (array, size, place);
}

void display (int array[], int size)
{
    int i;
    for (i=0; i < size; ++i){
        printf("%d\n", array[i]);
    }
    printf("\n");
}


