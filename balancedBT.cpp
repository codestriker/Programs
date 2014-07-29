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

int max(int a, int b)
{
  return (a >= b)? a: b;
}

void isBalanced(struct node *node, int &l, int &r, int& val)
{
    
    if (node == NULL)
    {
        return;
    }

    isBalanced(node->left, l, r, val) ;
    isBalanced(node->right, l, r, val);
    
    if (abs(l-r) > 1)
    {
        val = 0;
    }
    if (node->left)
        l = max(l, r) + 1;
    if (node->right)
        r = max(l, r) + 1;
    
    if (node->right == NULL && node->left == NULL)
    {
        l = 0;
        r = 0;
    }
        
    cout<<endl<<"Node: "<<node->data<<"  l:"<<l<<"  r:"<<r;
}

int main()
{
    struct node *root = newNode(1);
    int val = 1, l=0, r=0;
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
 
    isBalanced(root, l, r, val);
    if (val)
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");    
 
    getchar();
    return 0;
}
