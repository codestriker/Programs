#include<iostream.h>

// A tree node
struct node
{
    int data;
    struct node *left, *right;
};
 
// A utility function to create a new tree node
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}
 
// Standard Inorder traversal of tree
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}

void changeLeft(struct node *node)
{
    if (node==NULL)
        return;
    static struct node *prev = NULL;
    
    changeLeft(node->left);
    
    
    
    if(prev)
        cout<<node->data<<" "<<prev->data<<endl;
    prev=node;
    
    changeLeft(node->right);
    
     
    
}
// Driver program to test above functions
int main(void)
{
    // Let us create the tree shown in above diagram
    struct node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(16);
    root->left->left  = newNode(12);
    root->left->right = newNode(14);
    root->right->left = newNode(19);
    root->right->right = newNode(21);
     
    /*printf("\nInorder Tree Traversal\n\n");
    inorder(root);*/
 
    changeLeft(root);
/*    struct node *head = BTToDLL(root);
 
    printf("\n\n\t\tDLL Traversal\n\n");
    printList(head);*/
    getchar();
    return 0;
}
