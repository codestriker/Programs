#include<iostream.h>
#include<algorithm>

typedef struct node Node;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void printBT(Node *node)
{
    if(node == NULL)
        return;
    printBT(node->left);
    cout<<node->data<<"  ";
    printBT(node->right);
}

Node* newNode(int data)
{
    Node* n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n; 
}

Node* createBT(Node* curr, int data)
{
    if (curr == NULL)
        return newNode(data);
    
    if (curr->data < data)
        curr->right = createBT(curr->right, data);
    else
        curr->left = createBT(curr->left, data);
    
    return curr;
}

int size(Node *node)
{
    if(node == NULL)
        return 0;
        
    return 1 + size(node->left) + size(node->right);
}

void maxBTDepth(Node* node, int* maxDepth, int depth)
{
    if(node == NULL)
    {
        if(depth > *maxDepth)
            *maxDepth = depth;
        return;    
    }

    cout<<node->data<<" "<<depth<<"\n";
    maxBTDepth(node->left, maxDepth, depth+1);
    cout<<node->data<<" "<<depth<<"\n";
    maxBTDepth(node->right, maxDepth, depth+1);
}

int maxBTDepth1(Node* node)
{
    if(node == NULL)
    {
        return 0;    
    }

    cout<<node->data<<"  ";
    return 1 + std::max(maxBTDepth1(node->left), maxBTDepth1(node->right));
}

int maxDepth2(Node* node) { 

  if (node==NULL) { 
    return(0); 
  } 
  else { 
    // compute the depth of each subtree 
    int lDepth = maxDepth2(node->left); 
    int rDepth = maxDepth2(node->right);
    // use the larger one 
    cout<<node->data<<"  "<<lDepth<<"  "<<rDepth<<"\n";
    if (lDepth > rDepth)
         return(lDepth+1); 
    else
         return(rDepth+1); 
  } 
} 

int pathSum(Node *node, int num, int* arr, int idx)
{
    if(num == 0){
        cout<<"\nPrinting path for sum: ";
        for(int i=0; i<idx; i++)
            cout<<arr[i]<<"  ";
        return 1;
    }
        
    if(node==NULL)
        return 0;

    arr[idx]=node->data;
    cout<<node->data<<" "<<num<<" "<<idx<<"  "<<arr[idx]<<endl;
    return (pathSum(node->left, num-node->data, arr, idx+1) ||
            pathSum(node->right, num-node->data, arr, idx+1));
}

void mirror(Node *node)
{
    if(node==NULL)
        return;
        
    mirror(node->left);
    mirror(node->right);
    
    Node* tmp = node->left;
    node->left = node->right;
    node->right = tmp;

    return;
}

int main()
{
    Node* head = newNode(6);
    createBT(head, 3);
    createBT(head, 8);
    createBT(head, 1);
    createBT(head, 4);
    createBT(head, 5);
    //createBT(head, 1);
    //createBT(head, 11);
    //createBT(head, 10);

    printBT(head);
    
    
    cout<<"\n\nSize: "<<size(head);
    
    int maxDepth = 0;
    cout<<"\n--------------\n";
    //maxBTDepth(head, &maxDepth, 0);
    //cout<<"\nMax Dept: "<<maxDepth;
    cout<<"\n\nMax Dept: "<<maxBTDepth1(head);
    //cout<<"\nMax Dept: "<<maxDepth2(head);
    
    cout<<"\n--------------\n";
    int arr[10];
    cout<<"\n\nPathsum: "<<pathSum(head, 13, arr, 0);
    
    cout<<"\n------- Mirror -------\n";
    mirror(head);
    printBT(head);
        
    getchar();
    return 0;
}
