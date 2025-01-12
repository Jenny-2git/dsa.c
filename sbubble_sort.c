// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//     int c, i,j,n;
//     printf("total = ");
//     scanf("%d",&n);
//     int a[n];
//     for (i=0 ; i<n ; i++){
//         printf("enter =");
//         scanf("%d",&a[i]);
//     }
//     int flag;
//     for (i=0;i<n-1 ; i++){
//         flag=0;
//         for (j=0 ; j<n-1-i ; j++){
            
//             if (a[j]>a[j+1]){
//                 c=a[j+1];
//                 a[j+1]=a[j];
//                 a[j]=c;
//                 flag++;

//             }
//         if (flag==0){
//             break;
//         }
            
//         }
//     }
//     for (i=0 ; i<n ; i++){
//         printf("%d ",a[i]);
//     }
                       
// }





#include <stdio.h>


int main() {
    int c, i, j, n;

    // Correctly read the total number of elements
    printf("Enter total number of elements: ");
    scanf("%d", &n);

    // Declare the array with the specified size
    int a[n];

    // Read the elements into the array
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    // Bubble sort algorithm
    int flag;
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                // Swap elements
                c = a[j + 1];
                a[j + 1] = a[j];
                a[j] = c;
                flag = 1; // Set flag to indicate a swap occurred
            }
        }
        // If no swaps occurred, the array is sorted
        if (flag == 0) {
            break;
        }
    }

    // Output the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}




