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

/*void printLevelWise(struct node* root)
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
}*/

void printLevelWise(struct node* root, int level, multimap <int, int> &nodeMap, int &height)
{
    if (root == NULL)
        return;
    
    if (level > height)
        height = level;
    
    //nodeMap[level] = root->data;
    nodeMap.insert(std::make_pair(level, root->data));

    printLevelWise(root->left, level+1, nodeMap, height);
    printLevelWise(root->right, level+1, nodeMap, height);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
    
    //printLevelWise(root);
    
    multimap <int, int> nodeMap;
    int height = 0;
    printLevelWise(root, 0, nodeMap, height);
    for( multimap<int, int>::iterator ii=nodeMap.begin(); ii!=nodeMap.end(); ++ii)
   {
       cout << "Level "<<(*ii).first<< ": " << (*ii).second << endl;

   }
    
    getchar();
    return 0;
}
