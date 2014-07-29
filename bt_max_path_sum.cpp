#include<iostream>

using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
int height(struct node* node)
{
   /* base case tree is empty */
   if(node == NULL)
       return 0;
 
   /* If tree is not empty then height = 1 + max of left 
      height and right heights */   
   return 1 + max(height(node->left), height(node->right));
} 
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* returns maximum of two integers */
int max(int a, int b)
{
  return (a >= b)? a: b;
}

int maxPathSum(struct node * tree, int *val)
{
    static int sum = 0;
    int lSum=0, rSum=0;
   /* base case where tree is empty */
   if (tree == 0)
   {
        return 0;
   }
 
  lSum = maxPathSum(tree->left, val);
  rSum = maxPathSum(tree->right, val);
 
 
  sum = max(lSum+rSum,max(lSum, rSum)) + tree->data;
  if (sum > *val)
     *val = sum;

    cout<<"tree->data "<<tree->data<<" lSum:"<<lSum<<" rSum:"<<rSum<<" val:"<<*val<<" sum:"<<sum<<endl;

  return max(lSum, rSum) + tree->data;
} 
 
 
   
 
/* Driver program to test above functions*/
int main()
{
 
  /* Constructed binary tree is 
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(-20);
  root->left        = newNode(3);
  root->right       = newNode(4);
  root->left->left        = newNode(5);
  root->left->right        = newNode(5);

//  root->left->left  = newNode(4);
//  root->left->right = newNode(5);
 
 int val=0;
  printf("\nMax Path Sum of the given binary tree is %d", maxPathSum(root, &val));
  cout<<" "<<val;
 
  getchar();
  return 0;
}
