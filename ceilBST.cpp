#include<iostream>
#include<stdlib.h>

using namespace std;
 
struct Node
{
    int data;
    struct Node *left, *right;
};

typedef struct Node node;
 
// A utility function to create a new Binary Tree Node
struct Node *newNode(int item)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void Ceil(node* root, int val, int *ceilVal)
{
    if (root==NULL)
        return;
    
    if (root->data == val)
        *ceilVal = root->data;

    if (root->data < val)
        Ceil(root->right, val, ceilVal);
    
    if (root->data > val)
    {
        if (root->data > val &&  root->data < *ceilVal)
            *ceilVal = root->data;
            Ceil(root->left, val, ceilVal);
    }
}

// Driver Program to test above functions
int main()
{
    node *root = newNode(8);
 
    root->left = newNode(4);
    root->right = newNode(12);
 
    root->left->left = newNode(2);
    root->left->right = newNode(6);
 
    root->right->left = newNode(10);
    root->right->right = newNode(14);
    
    int ceilVal = 100000;
    cout <<ceilVal<<endl;
 
     for(int i = 0; i < 16; i++)
     {
            Ceil(root, i, &ceilVal);
            printf("%d  %d\n", i, ceilVal);
            ceilVal = 100000;
     }
 //   for(int i = 0; i < 16; i++)
 //       printf("%d  %d\n", i, Ceil(root, i));
 
    getchar();
    return 0;
}
