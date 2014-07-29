#include<iostream>
#include<stdlib.h>
 
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new Binary Tree Node
struct Node *newNode(int item)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Recursive function to print right view of a binary tree.
void rightViewUtil(struct Node *node, int level, int *max_level)
{
    if (node==NULL)
        return;
    if (level > *max_level)
    {
        std::cout<<node->data<<"  ";
        *max_level = level;
    }
    rightViewUtil(node->right, level+1, max_level);
    rightViewUtil(node->left, level+1, max_level);
}
  

/*void rightViewUtil(struct Node *root)
{
    while (root!=NULL)
    {
        std::cout<<root->data<<"  ";
        if( root->right)
        {
            if(root->right->right==NULL && root->right->left==NULL)
            {
                std::cout<<root->right<<"  ";
                root = root->left;
            }
            else
                root = root->right;
        }
        else if( root->left)
            root = root->left;
        else
        {
            root = NULL;
        }
    }
}*/

// A wrapper over rightViewUtil()
void rightView(struct Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
    //rightViewUtil(root);
}
 
// Driver Program to test above functions
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
 
    rightView(root);
 
    getchar();
    return 0;
}
