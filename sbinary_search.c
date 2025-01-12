#include <stdio.h>

// int binary_search(int a[], int n, int data) {
//     int L, R, mid;
//     L = 0;
//     R = n - 1;

//     while (L <= R) { // Changed to L <= R to include the middle element
//         mid = (L + R) / 2; // Corrected assignment of mid
//         if (a[mid] == data) { // Changed i to mid
//             return mid; // Return the index of the found element
//         } else if (data < a[mid]) { // Corrected condition
//             R = mid - 1;
//         } else { // Changed to else
//             L = mid + 1;
//         }
//     }
//     return -1; // Return -1 if the element is not found
// }


int binsearch(int a[], int n,int data){
    int low,high,mid;
    low=0;
    high=n-1;
    mid=(low+high)/2;
    if(data=a[mid]){
        return mid;
    }
    else if(data>mid){
        low=a[mid]+1;
    }
    else {
        high=a[mid]-1;
    }
}

int main() {
    int a[10], n, i, result;
    printf("Total elements = ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Populate the array
    }

    int data;
    printf("Enter the element to search: ");
    scanf("%d", &data);

    result = binsearch(a, n, data); // Call the binary search function
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found.\n");
    }

    return 0; // Return success
}