#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left,*right;
}; 

struct node *insert(struct node *root, int x) {
    if (root == NULL) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    if (x < root->data) {
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}

void preorder (struct node *root,int x){
    if(root==0){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if (root==0){
        return;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

void postorder(struct node *root){
    if (root==0){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

int main() {
    struct node *root = NULL;
    int x;
    while (1) {
        printf("\nEnter data (-1 to stop): ");
        scanf("%d", &x);
        if (x == -1) {
            break;
        }
        root = insert(root, x);
    }
    printf("Inorder is = ");
    inorder(root);
    printf("\nPreorder is = ");
    preorder(root);
    printf("\nPostorder is = ");
    postorder(root);
}