#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to construct a balanced BST from sorted array
struct node* sortedArrayToBST(int arr[], int start, int end) {
    // Base case
    if (start > end) {
        return NULL;
    }

    // Find the middle element
    int mid = (start + end) / 2;
    struct node* root = newNode(arr[mid]); // Create a new node with the middle element

    // Recursively construct the left and right subtrees
    root->left = sortedArrayToBST(arr, start, mid - 1); // Left half
    root->right = sortedArrayToBST(arr, mid + 1, end); // Right half

    return root; // Return the constructed BST
}

// Function to print the inorder traversal of the BST
void inorder(struct node* root) {
    if (root == NULL) return; // Base case
    inorder(root->left); // Visit left subtree
    printf("%d ", root->data); // Print current node
    inorder(root->right); // Visit right subtree
}

// Example usage
int main() {
    int inorder[10] ; // Sorted array
    for(i=0;i<10;i++){
        printf("enter data=");
        scanf("%d",&inorder[i]);
    }
    inorder(inorder);

    int size = sizeof(inorder) / sizeof(inorder[0]); // Calculate size
    struct node* root = sortedArrayToBST(inorder, 0, size - 1); // Construct BST

    printf("Inorder traversal of the constructed BST: ");
    inorder(root); // Print the inorder traversal of the BST

    return 0;
}