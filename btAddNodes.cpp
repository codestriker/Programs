#include<iostream.h>

// A tree node
struct node
{
    int data;
    struct node *left, *right;
};
 
// A utility function to create a new tree node
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}
 
// Standard Inorder traversal of tree
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}

void addNodeSum(struct node *root)
{
    if (root==NULL)
        return;
    
    addNodeSum(root->left);
    addNodeSum(root->right);
    
    if (root->left)
        root->data += root->left->data;
    
    if (root->right)
        root->data += root->right->data;
}

// Driver program to test above functions
int main(void)
{
    // Let us create the tree shown in above diagram
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    addNodeSum(root);
    inorder(root);
    getchar();
    return 0;
}
