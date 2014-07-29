#include<iostream>
#include<stdlib.h>
#include <queue>
#include <map>

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

void Inorder(struct node *node)
{
    if (node==NULL)
        return;
    Inorder(node->left);
    cout<<node->data<<"  ";
    Inorder(node->right);
}

void treeTansform(struct node *node)
{
    static int sum = 0;
    if (node==NULL)
        return;

    treeTansform(node->right);
    sum += node->data;
    node->data = sum - node->data;
    //cout<<node->data<<" "<<sum<<endl;
    treeTansform(node->left);
  //  sum += node->data;
}

int main()
{
    struct node *root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);
    
    Inorder(root);

    cout<<endl;
    treeTansform(root);
    Inorder(root);

    getchar();
    return 0;
}
