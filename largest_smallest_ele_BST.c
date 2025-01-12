#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *create() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("enter data = ");
    scanf("%d", &x);
    if (x == -1) {
        free(newnode); // Free the allocated memory
        return NULL;   // Return NULL for no node
    }
    newnode->data = x;
    printf("enter left child of %d \n", x);
    newnode->left = create();
    if (newnode->left->data >newnode->data){
        printf("left child is greater than parent");
        free(newnode->left);
        newnode->left=NULL;
    }
    printf("enter right child of %d \n", x);
    newnode->right = create();
    if (newnode->right->data <newnode->data){
        printf("right child is smaller than parent");
        free(newnode->right);
        newnode->right=NULL;
    }
    return newnode; // Return the created node
}

struct node *deletesmallest(struct node *root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left != NULL) {
        root->left = deletesmallest(root->left);
        return root;
    }
    struct node *temp = root->right;
    free(root);
    return temp; // Return pointer to the new root
}
struct node *deletelargest(struct node *root){
    if (root==NULL){
        return NULL;
    }
    if (root->right!=NULL){
        root->right=deletelargest(root->right);
        return root;
    }
    struct node *temp=root->left;
    free(root);
    return temp;
}
int countnodes(struct node *root){
    if(root==NULL){
        return NULL;
    }
    int Lcount=countnodes(root->left);
    int Rcount=countnodes(root->right);
    return 1+Lcount+Rcount;
    
   
}
int main() {
    // Example tree creation
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = 1;
    root->left = (struct node*)malloc(sizeof(struct node));
    root->left->data = 2;
    root->right = (struct node*)malloc(sizeof(struct node));
    root->right->data = 3;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = NULL;
    root->right->right = NULL;

    // Count the nodes
    int totalNodes = countnodes(root);
    printf("Total nodes = %d\n", totalNodes);

    // Free allocated memory (not shown for simplicity)
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}

// void main (){
//     struct node *root;
//     root=0;
//     root=create();
//     deletelargest(root);
//     deletesmallest(root);
//     countnodes(root);
// }
