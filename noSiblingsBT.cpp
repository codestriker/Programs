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

void countNoSibling(node* root, int& count)
{
    if (!root)
        return;
    countNoSibling(root->left, count);
    countNoSibling(root->right, count);
    if (root->left==NULL && root->right!=NULL) {
        cout<<root->right->data<<"  ";
        count++;
    }
    if (root->left!=NULL && root->right==NULL) {
        cout<<root->left->data<<"  ";
        count++;
    }
}

// Driver Program to test above functions
int main()
{
    node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->right = newnode(4);
    root->right->left = newnode(5);
    root->right->left->left = newnode(6);

    int count = 0;
    countNoSibling(root, count);
    cout<<count;
    getchar();
    return 0;
}
