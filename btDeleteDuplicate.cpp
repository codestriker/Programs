#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}

void printInorder(struct node* node)
{
    if (node==NULL)
        return;
        
    printInorder(node->left);
    cout<<node->data<<"  ";
    printInorder(node->right);
}

void deleteDuplicate(struct node* node)
{
    if (node==NULL)
        return;
}

int main()
{
    struct node *root = newNode(5);
    root->left = newNode(3);
    root->left->right = newNode(4);
    root->left->left = newNode(3);
    root->left->left->left = newNode(1);
    
    printInorder(root);
    
    deleteDuplicate(root);
    
    getchar();
    return 0;
}
