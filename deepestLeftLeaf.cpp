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
struct Node *newnode(int item)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void deepestLeftLeaf(node* root, int level, int* maxLevel, int *val)
{
    if (root==NULL)
        return;

    deepestLeftLeaf(root->left, level+1, maxLevel, val);
    deepestLeftLeaf(root->right, level+1, maxLevel, val);
    
    if (root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
    {
        if (level > *maxLevel)
        {
            *maxLevel = level;
            *val = root->left->data;   
        }
        return;
    }

}

// Driver Program to test above functions
int main()
{
    node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->right->left = newnode(5);
    root->right->left->right = newnode(6);

    int maxLevel=0, val=0;
    deepestLeftLeaf(root, 0, &maxLevel, &val);
    cout<<val;

    getchar();
    return 0;
}
