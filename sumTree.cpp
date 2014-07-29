#include<iostream>
#include<string.h>
#include <sstream> 
using namespace std;

/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

bool isLeaf(struct node* node)
{
    if (node->right==NULL && node->left==NULL)
    {
        return true;
    }
    else
        return false;
}
// solution1
int isSumTree(struct node* node)
{
    if (node==NULL)
        return 0;
    if (node->left==NULL && node->right==NULL)
        return node->data;
    if (isSumTree(node->left) + isSumTree(node->right) == node->data)
    {
        cout<<"Match:"<<node->data<<endl;
        return node->data*2;
    }
    else
    {
        cout<<"No Match:"<<node->data<<endl;
        return 0;
    }
}

/*bool isSumTree(struct node* node)
{
    // another soln above
    int sumLeft=0, sumRight=0;
    if (node==NULL)
    {   
        return true;
    }

    if (isLeaf(node))
    {
        cout<<"leaf:"<<node->data<<endl;
        return true;
    }

    if (isSumTree(node->left))
    {
        cout<<"match left"<<node->data<<endl;
        if(node->left && node->left->left)
            sumLeft = node->left->data * 2;
        else if (node->left)
            sumLeft = node->left->data;
        else
            sumLeft = 0;
    }
    
    if (isSumTree(node->right))
    {
        cout<<"match right "<<node->data<<endl;
        if (node->right && node->right->right)
            sumRight = node->right->data * 2;
        else if (node->right)
            sumRight = node->right->data;
        else
            sumRight = 0;
    }

    cout<<"sumLeft:"<<sumLeft<<"    sumRight:"<<sumRight<<"  "<<node->data<<endl;
    if (sumLeft + sumRight == node->data)
         return true;
    else
        return false;
  
}
*/
/* Helper function that allocates a new node
 with the given data and NULL left and right
 pointers.
*/
struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
/* Driver program to test above function */
int main()
{
    struct node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
    if(isSumTree(root))
        printf("The given tree is a SumTree ");
    else
        printf("The given tree is not a SumTree ");
 
    getchar();
    return 0;
}
