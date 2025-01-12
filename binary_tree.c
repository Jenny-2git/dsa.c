#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};

struct node *create(){
    struct node *newnode;
    int x;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf ("\nenter data =");
    scanf("%d", &x);
    if (x==-1){
        return 0;
    }
    newnode->data=x;
    printf("enter left child of %d",x);
    newnode->left=create();
    printf("enter right child of %d",x);
    newnode->right=create();
    return newnode;
}

void main(){
    struct node *root;
    root=0;
    root=create();
    printf("inorder is =");
    inorder(root);
    printf("preorder is =");
    preorder(root);
    printf("postorder is =");
    postorder(root);
}

void preorder (struct node *root){
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

// #include <stdio.h>
// #include <stdlib.h>
// struct node{
//     int data;
//     struct node *left,*right;

// };
// struct node *create(){
//     struct node *newnode;
//     int x;
//     newnode =(struct ndoe *)malloc(sizeof(struct node));
//     printf("enter data =");
//     scanf("%d", &x);
//     if (x==-1){
//         return;
//     }
//     newnode->data=x;
//     printf("left child of %d",x);
//     newnode->left=create();
//     printf("right child of %d,x");
//     newnode->right=create();
//     return newnode;
// }
// void preorder(struct node *root){
//     if (root==0){
//         return;
//     }
//     printf("%d",root->data);
//     preorder(root->left);
//     preorder(root->right);

// }
// void postorder(struct node *root){
//     if (root==0){
//         return;
//     }
//     postorder(root->left);
//     postorder(root->right);
//     printf("%d",root->data);

// }
// void inorder(struct node *root){
//     if (root==0){
//         return;
//     }
//     inorder(root->left);
//     printf("%d",root->data);
//     inorder(root->right);


// }
// void main (){
//     struct node *root;
//     root=0;
//     root=create();
//     printf("preorder is =");
//     preorder(root);
//     postorder(root);
//     inorder(root);
// }





