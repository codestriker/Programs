#include<iostream.h>

int arr[] = {3, 1, 2, 4, 5};

struct BinaryTree
{
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
};

typedef struct BinaryTree BT;

void BtCreate(BT **head)
{
    *head = new BT;
    BT *curr = *head;
    curr->data = arr[0];
        curr->left = new BT;
            curr->left->data = arr[1];
            curr->left->right = new BT;
                curr->left->right->data = arr[2];
                curr->left->right->right = NULL;
                curr->left->right->left = NULL;
            curr->left->left = NULL;
        curr->right = new BT;
            curr->right->data = arr[3];
            curr->right->right = new BT;
                curr->right->right->data = arr[4];
                curr->right->right->right = NULL;
                curr->right->right->left = NULL;
            curr->right->left = NULL;            
}

void preorder(BT *curr)
{
    if(!curr)
        return;
    preorder(curr->left);
    cout<<curr->data;
    preorder(curr->right);
}

int main()
{
    BT *head;
    BtCreate(&head);
    preorder(head);
    getchar();
    return 0;
}
