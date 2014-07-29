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

void printLevelWise(struct node* root)
{
    if (root==NULL)
        return;
    
    queue <struct node *> nodeQueue;
    nodeQueue.push(root);
    
    while (1)
    {
       int nodeCount = nodeQueue.size();
       if (nodeCount ==0)
        return;
       cout<<endl;
       
       while (nodeCount > 0)
       {
            struct node* node = nodeQueue.front();
            nodeQueue.pop();
            nodeCount--;
            cout<<node->data<<"  ";

            if (node->left)
                nodeQueue.push(node->left);        
            if (node->right)
                nodeQueue.push(node->right);    
       }
    }
}

void reverseAlternateLevel(struct node* root)
{
    if (root==NULL)
        return;
    
    int level = 0;
    queue <struct node *> nodeQueue;
    vector <struct node *> nodeVector;
    nodeQueue.push(root);
    
    while (1)
    {
       int nodeCount = nodeQueue.size();
       if (nodeCount ==0)
        return;
       
       level++;
       cout<<endl;

       while (nodeCount > 0)
       {
            struct node* node = nodeQueue.front();
            nodeQueue.pop();
            nodeCount--;
            cout<<level<<":"<<node->data<<"  ";
            if (node->left)
            {
                nodeQueue.push(node->left); 
                if (level%2 != 0)
                    nodeVector.push_back(node->left);
                      
            }     
            if (node->right)
            {
                nodeQueue.push(node->right);  
                if (level%2 != 0)
                    nodeVector.push_back(node->right);
            }  
       }
       if (level%2 != 0)
       {
            if (!nodeVector.empty())
            {
                cout<<"\nNode vector size:" <<nodeVector.size()<<" ";
                for (int i=0; i<nodeVector.size(); i++)
                    cout<< nodeVector[i]->data<<" ";
                cout<<endl;
               int j=nodeVector.size()-1;
               for (int i=0; i<=nodeVector.size()/2-1; i++, j--)
               {
                    int tmp = nodeVector[i]->data;
                    nodeVector[i]->data = nodeVector[j]->data;
                    nodeVector[j]->data = tmp;
               }
               nodeVector.clear();
               cout<<"\nNode vector clean up. size:" <<nodeVector.size()<<" ";
           }
        }
    }
}


int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);
    printLevelWise(root);
    
    reverseAlternateLevel(root);
    cout<<"\n\n\n";
    
    printLevelWise(root);
    getchar();
    return 0;
}
