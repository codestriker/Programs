#include<iostream.h>

/* Link list node */
struct LNode
{
    int data;
    struct LNode* right;
    struct LNode* left;
};

typedef struct LNode Node;

int arr[] = { 1, 2, 3, 4, 5 ,6 , 7};

Node* createNode(int data)
{
    Node *tmp = new Node;
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

Node* createTree(int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end)/2;

    Node *tmp = createNode(arr[mid]);
    tmp->left = createTree(start, mid-1);
    tmp->right = createTree(mid+1, end);
    return tmp;
}

void inorder(Node *node)
{
    if(node==NULL)
        return;
        
    inorder(node->left);
    
    inorder(node->right);
    cout<<node->data<<"  ";
    
}
int main()
{
    cout<<(sizeof(arr)/sizeof(int))-1<<endl;
    Node *head = createTree(0, (sizeof(arr)/sizeof(int))-1);
    inorder(head);
    
    getchar();
    return 0;
}
