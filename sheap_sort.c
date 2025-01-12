#include <stdio.h>
#include <stdlib.h>

void insertheap(int a[], int *n, int value) {
    (*n)++; 
    a[*n - 1] = value; 
    int i = *n - 1; 
   
    while (i > 0) {
        int parent = (i - 1) / 2; // Calculate parent index
        if (a[parent] < a[i]) {
            swap(&a[parent], &a[i]); // Swap if parent is less than current
            i = parent; // Move up to the parent
        } else {
            break; // If the heap property is satisfied, break
        }
     }
}


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void maxheapify(int a[], int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && a[l] > a[largest]) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        swap(&a[i], &a[largest]); // Swap root with largest
        maxheapify(a, n, largest); // Recursively heapify the affected sub-tree
    }
}

void buildMaxHeap(int a[], int n) {
    // Build a max heap from the array
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxheapify(a, n, i);
    }
}

int main() {
    int a[10], n, i;
    printf("Enter length: ");
    scanf("%d", &n);
    
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    buildMaxHeap(a, n); // Build max heap from the array
    
    printf("Max Heap: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}