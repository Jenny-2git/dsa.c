#include <stdio.h>

void merge(int arr[], int l, int mid, int h) {
    int i, j, k;
    int m = mid - l + 1;
    int n = h - mid;

    int L[m], R[n];

    for (i = 0; i < m; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 

    while (i < m && j < n) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < m) {
        arr[k] = L[i];
        i++;
        k++;
    }
        
          
    while (j < n) {
        arr[k] = R[j];
        j++;
        k++;   
    }
}

void algo_mergesort(int arr[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        algo_mergesort(arr, l, mid);
        algo_mergesort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

int main() {
    int a[6], i;
    printf("Enter 6 integers:\n");
    for (i = 0; i < 6; i++) {
        printf("Enter = ");
        scanf("%d", &a[i]);
    }
    algo_mergesort(a, 0, 5);

    printf("Sorted array:\n");
    for (i = 0; i < 6; i++) {
        printf("%d \n", a[i]);
    }
    //printf("\n");
    //return 0;
}






