#include<iostream>
#include<string.h>
#include <sstream> 
using namespace std;

class BinaryTree
{
    public:
        BinaryTree(int x)
        {
            data = x;
            left = NULL;
            right = NULL;
        }
        
        //void createBT(int *arr, int size);
        void insert(int data);
        void print(BinaryTree* node);
        void printSum(BinaryTree* head, int sum, string str);

//    private:
        int data;
        BinaryTree* left;
        BinaryTree* right;
};

void BinaryTree::insert(int x)
{
    BinaryTree *node = this;

    BinaryTree *tmp = new BinaryTree(x);
    
    while( node!=NULL)
    {
        if (x<node->data)
        {
            if(node->left==NULL)
            {
                node->left = tmp;
                break;
            }
            node = node->left;
        }
        else
        {
            if(node->right==NULL)
            {
                node->right = tmp;
                break;
            }
            node = node->right;
        }
    }
}

void BinaryTree::print(BinaryTree *node)
{
    if (node==NULL)
        return;
    print(node->left);
    cout<<node->data<<"\t";
    print(node->right);
}

void BinaryTree::printSum(BinaryTree* node, int sum, string str)
{

    if (node == NULL || sum<0)
        return;

    stringstream ss;//create a stringstream
    ss << node->data;//add number to the stream

    if (sum - node->data ==0)
    {
        cout<<"Found: "<<str + ","+ ss.str()<<endl;
        return;
    }

    printSum(node->left, sum-node->data, str + "," +ss.str());
    printSum(node->right, sum-node->data, str + "," + ss.str());
    
}

int main()
{
    int arr[] = {8, 5, 12, 7, 4, 3};
    
    BinaryTree *head = new BinaryTree(arr[0]);

    
    for(int i=1; i<sizeof(arr)/sizeof(arr[0]); i++)
        head->insert(arr[i]);
    //head->print(head);
    
    head->printSum(head, 20, "");
    getchar();
    return 0;
}
