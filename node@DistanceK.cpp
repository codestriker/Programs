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

int distanceOfNode(struct Node* root, struct Node* target, int level)
{
    if (root==NULL)
        return 0;

    if (root==target)
        return level;
    
    return (distanceOfNode(root->left, target, level+1) +
            distanceOfNode(root->right, target, level+1));
    
}

void printkdistanceNodeFwd(node* root, int k, int level)
{
    if (root==NULL || level>k)
        return;
  
    if (k==level)
        cout<<root->data<<" ";
        
    printkdistanceNodeFwd(root->left, k, level+1);
    printkdistanceNodeFwd(root->right, k, level+1);
}

node* getParent(node* node, node* target)
{
    struct Node* l=NULL, *r=NULL;
    if (node==NULL)
        return NULL;
    
    if (node->right == target || node->left == target)
    {
        return node;
    }
    
    l = getParent(node->left, target);
    r = getParent(node->right, target);
    
    return (l?l:r);
}

void adjust(node* node, node* target)//, node *fixRight, node *fixLeft)
{
    if (node==NULL)
        return;
    
    if (node->right == target)
    {
      //  fixRight = target->right;   
       // fixLeft = target->left;
        target->right = node;
        target->left = node->left;
        return;
    }
    
    if (node->left == target)
    {
        //fixRight = target->right;   
        //fixLeft = target->left;
        target->right = node;
        target->left = node->right;
        return;
    }
     
     adjust(node->right, target);
     adjust(node->left, target);
}

// Driver Program to test above functions
int main()
{
    node * root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    node * target = root->left->right;
    int k=2;
    //cout<<distanceOfNode(root, target, 1);
    printkdistanceNodeFwd(target, k, 0);
    if (target!= root)
    {
        node *parent = getParent(root, target);
        cout<<parent->data;
        //printkdistanceNodeFwd(target->right, k, 0);
        //printkdistanceNodeFwd(target->left, k-1, 0);
    }
    getchar();
    return 0;
}
