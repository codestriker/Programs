#include<iostream>

using namespace std;
#define N 30  // array size
#define K 20  // max value in the array. used for random number calculation

class TrinaryTreeStruct
{
    public:
        int data;
        TrinaryTreeStruct* left;
        TrinaryTreeStruct* middle;
        TrinaryTreeStruct* right;
        
        TrinaryTreeStruct(int val): data(val), right(NULL), middle(NULL), left(NULL) {}
        TrinaryTreeStruct() {}
};

class TrinaryTree: public TrinaryTreeStruct
{
    private:
        TrinaryTreeStruct* root;

    public:
        TrinaryTree(): root(NULL) {}

        void insertNode(int val);
        void insertNode(TrinaryTreeStruct* node, int val);

        void deleteNode(int val);
        void deleteNode(TrinaryTreeStruct* node, int val);

        void printInOrder();
        void printInOrder(TrinaryTreeStruct* node);

        bool isLeafNode(TrinaryTreeStruct* node);
        bool adjustSuccessorTree(TrinaryTreeStruct* node);
        bool adjustPredecessorTree(TrinaryTreeStruct* node);
        TrinaryTreeStruct* searchTrinaryTree(TrinaryTreeStruct* node, 
                                             TrinaryTreeStruct** parent, int val);

};

bool TrinaryTree::isLeafNode(TrinaryTreeStruct* node)
{
    if (node==NULL)
        return false;
    
    if (node->left==NULL && node->middle==NULL && node->right==NULL)
        return true;

    return false;
}

// Searches value in the trinary tree. 
// Returns corresponding node and parent node if value is present.
TrinaryTreeStruct* TrinaryTree::searchTrinaryTree(TrinaryTreeStruct* node,
                                                  TrinaryTreeStruct** parent,
                                                  int val)
{
    if (node==NULL)
        return NULL;

    *parent = NULL;

    while (node!=NULL)
    {
        if (node->data == val)
            return node;
        else if (node->data < val){
            *parent = node;
            node = node->right;
        }
        else {
            *parent = node;
            node = node->left;
        }
    }
    return NULL;
}

// Does adjustment in the successor tree if node has right child.
// Finds the successor and replace node with it.
bool TrinaryTree::adjustSuccessorTree(TrinaryTreeStruct* node)
{
    TrinaryTreeStruct* parent = node;
    TrinaryTreeStruct* child = parent->right;

    if (child==NULL)
        return false;

    while (child->left != NULL)
    {
        parent = child;
        child = child->left;
    }

    if (parent->left == child)
        parent->left = child->right;
    else
        parent->right = child->right;

    cout<<"\nNode:"<<node->data<<" deleted in successor tree\n";

    node->data = child->data;
    node->middle = child->middle;
    delete(child); 

    return true;
}

// Does adjustment in the predecessor tree if node has left child
// Finds the predecessor and replace node with it.
bool TrinaryTree::adjustPredecessorTree(TrinaryTreeStruct* node)
{
    TrinaryTreeStruct* parent = node;
    TrinaryTreeStruct* child = parent->left;

    if (child==NULL)
        return false;
    
    while (child->right != NULL)
    {
        parent = child;
        child = child->right;
    }

    if (parent->right == child)
        parent->right = child->left;
    else
       parent->left = child->left;

    cout<<"\nNode:"<<node->data<<" deleted in predecessor tree"<<"\n";

    node->data = child->data;
    node->middle = child->middle;
    delete(child); 
    
    return true;
}

void TrinaryTree::deleteNode(int val)
{
    TrinaryTreeStruct  *parent;
    TrinaryTreeStruct* node = searchTrinaryTree(this->root, &parent, val);

    if (node == NULL)
    {
        cout<<"\nValue "<<val<<" not found in the tree"<<endl;
        return;
    }
    else if (isLeafNode(node))
    {
        if (parent!=NULL) {
            if (parent->left == node)
                parent->left = NULL;
                
            if (parent->right == node)
                parent->right = NULL;
        }
        if (node == this->root)
            this->root = NULL;
        delete(node);
        cout<<"\nNode: "<<val<<" deleted is child "<<"\n";
        return;
    }
    else if (node->middle != NULL)
    {
        TrinaryTreeStruct* tmp = node->middle;
        node->middle = tmp->middle;
        delete tmp;
        cout<<"\nNode:"<<val<<" deleted in middle tree "<<"\n";
        return;
    }
    else if (adjustSuccessorTree(node) || adjustPredecessorTree(node))
    {
        return;
    }
    else
    {
        cout<<"\nNode not deleted\n";
    }
}

void TrinaryTree::insertNode(int val)
{
    if (this->root == NULL)
        this->root = new TrinaryTreeStruct(val);
    else
        insertNode(this->root, val);
}

void TrinaryTree::insertNode(TrinaryTreeStruct* node, int val)
{
    if (node==NULL)
        return;
    
    while (node != NULL)
    {
        if (val < node->data)
        {
            if (node->left == NULL)
            {
                node->left = new TrinaryTreeStruct(val);
                return;
            }
            node = node->left;
        }
        else if (val == node->data)
        {
            if (node->middle == NULL)
            {
                node->middle = new TrinaryTreeStruct(val);
                return;
            }
            node = node->middle;
        }
        else
        {
            if (node->right == NULL)
            {
                node->right = new TrinaryTreeStruct(val);
                return;
            }
            node = node->right;
        }
    }
}

void TrinaryTree::printInOrder()
{
    if (this->root != NULL)
        printInOrder(this->root);
}

void TrinaryTree::printInOrder(TrinaryTreeStruct* node)
{
    if (node==NULL)
        return;
    
    printInOrder(node->left);
    cout<<node->data<<"   ";
    printInOrder(node->middle);
    printInOrder(node->right);
}

int main()
{
    TrinaryTree treeHead;

    int arr[N];
    for (int i=0; i<N; i++)
    {
        arr[i] = rand() % K;
        treeHead.insertNode(arr[i]);  // insertion
        cout<<"Node inserted is "<<arr[i]<<endl;
    }

    cout<<endl<<"----------- INORDER -------------------"<<endl;
    treeHead.printInOrder();
    cout<<endl<<"---------------------------------------"<<endl;


     for (int i=N; i>0; i--)
     {
        int tmp = rand() % i;
        int val = arr[i-1];
        arr[i-1] = arr[tmp];
        arr[tmp] = val;
        treeHead.deleteNode(arr[i-1]);   // deletion
    cout<<endl<<"----------- INORDER -------------------"<<endl;
    treeHead.printInOrder();
    cout<<endl<<"---------------------------------------"<<endl;
        cout<<endl;
    }
    cout<<endl;

    getchar();
    return 0;
}
