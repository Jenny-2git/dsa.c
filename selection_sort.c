#include <stdio.h>

void swap (int *i,int *min){
    int c=*i;
    *i=*min;
    *min=c;

}
int main (){
    int c,a[5],i,min,j;
    for (i=0;i<5;i++){
        printf("enter =");
        scanf("%d",&a[i]);
    }
    for (i=0;i<4;i++){
        min=i;
        for (j=i+1; j<5; j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
            if (min!=i)
            {
               swap (&a[i], &a[min]);

            }

        }
    }
    for (i=0 ;i<5;i++){
        printf("sorted element...\n%d\n",a[i]);
    }
    return 0;

}

// #include <stdio.h>

// void swap(int *i, int *min) {
//     int c = *i;
//     *i = *min;
//     *min = c;
// }

// int main() {
//     int a[5], i, min, j;

//     // Input array elements
//     for (i = 0; i < 5; i++) {
//         printf("Enter element %d: ", i + 1);
//         scanf("%d", &a[i]);
//     }

//     // Selection sort
//     for (i = 0; i < 4; i++) {
//         min = i;
//         for (j = i + 1; j < 5; j++) {
//             if (a[min] > a[j]) {
//                 min = j;
//             }
//         }
//         // Swap only if min is different from i
//         if (min != i) {
//             swap(&a[i], &a[min]);
//         }
//     }

//     // Output sorted elements
//     for (i = 0; i < 5; i++) {
//         printf("Sorted element: %d\n", a[i]);
//     }
    
//     return 0;
// }
