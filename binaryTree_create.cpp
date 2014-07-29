#include<iostream.h>

int arr[] = {3, 5, 2, 8, 7, 1, 4, 5, 6};

struct BinaryTree
{
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
};

typedef struct BinaryTree BT;


void BtInsert( BT **curr, int idx)
{

    if(*curr == NULL) {
        *curr = new BT;
        (*curr)->data = arr[idx];
        (*curr)->left = NULL;
        (*curr)->right = NULL;
        return;
        
    }    
    if(arr[idx] > (*curr)->data) {
        cout<<"\nRecursive Right";
        BtInsert(&((*curr)->right), idx); 
    } else {
        cout<<"\nRecursive Left";
        BtInsert(&((*curr)->left), idx); 
    }
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
    BT *head = NULL;
    for(int i=0; i<sizeof(arr)/sizeof(int); i++) {
        BtInsert(&head, i);
    }
    cout<<"\n-------------------- PRINT ------------\n";
    preorder(head);
    getchar();
    return 0;
}
