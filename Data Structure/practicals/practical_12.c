/* Write Program to create Binary Search Tree and perform Inorder, Preorder and Postorder traversal. */

#include <stdio.h>
#include <stdlib.h>

struct Node *CreateNode(int elem);
void InsertInBST(struct Node *root, int elem);
struct Node* Insert(struct Node *root, int elem);
void PreOrder(struct Node *root);
void InOrder(struct Node *root);
void PreOrder(struct Node *root);

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *CreateNode(int elem)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = elem;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void InsertInBST(struct Node *root, int elem)
{
    struct Node *pre = NULL;
    while (root != NULL)
    {
        pre = root;
        if (elem == root->data)
        {  
            printf("number %d can't inserted, already present in BST \n\n", elem);
            return;
        }

        else if (elem < root->data)
        {
            root = root->left;
        }

        else
        {
             root = root->left;
        }
    }

    struct Node *p = CreateNode(elem);
    if (elem < pre->data)
    {
        pre->left = p;
    }
    else
    {
        pre->right = p;
        ;
    }
    printf("Inserted : %d\n", elem);
}



void PreOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(struct Node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

void PostOrder(struct Node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}

void main()
{

    struct Node *root = CreateNode(50);

     InsertInBST(root, 34);
     InsertInBST(root, 45);
     InsertInBST(root, 10);
   
    printf("Preorder treaversal\n");
    PreOrder(root);
    printf("\n\n");

    printf("Inorder Treaversal\n");
    InOrder(root);
    printf("\n\n");

    printf("Postorder Traversal\n");
    PostOrder(root);
}