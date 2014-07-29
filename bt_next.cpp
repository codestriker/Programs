#include<iostream.h>

struct BinaryTree
{
    int data;
    struct BinaryTree *right;
    struct BinaryTree* left;
    struct BinaryTree* next;
};

typedef struct BinaryTree BT;

BT * createNode(int x)
{
    BT* node = new BT;
    node->data = x;
    node->right = NULL;
    node->left = NULL;
    node->next = NULL;
    return node;
}

BT* createBT(int* arr, int low, int high)
{
    if (low>high)
        return NULL;
    int mid = (low+high)/2;
    BT *node = createNode(arr[mid]);
    node->left = createBT(arr, low, mid-1); 
    node->right = createBT(arr, mid+1, high);
    return node;
}

void inorder(BT* node)
{
    if (node==NULL)
        return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

BT* adjustNextPtr(BT* node)
{
    if (node==NULL)
        return NULL;

    BT* left = adjustNextPtr(node->left);
    BT* right = adjustNextPtr(node->right);

    if (left && right)
    {
        node->left->next = node->right;
        if (left->right && right->left)
            left->right->next = right->left;
    }

    return node;
}

void printNext(BT* node)
{
    if (node==NULL)
        return;
    printNext(node->left);

    if (node->next)
    {
        cout<<node->data<<" "<<node->next->data<<endl;
    }
    else
    {
        cout<<node->data<<endl;
    }
    printNext(node->right);
    //cout<<node->data<<" ";
}

int main()
{
    int arr[] = {1, 3, 4, 5, 8, 10, 12};
    int size = sizeof(arr)/sizeof(arr[0]);
    BT* head = createBT(arr, 0, size-1);
  //  inorder(head);
    BT* head1 = adjustNextPtr(head);
    printNext(head1);
    getchar();
    return 0;
}
