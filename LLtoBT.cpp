
#include<iostream.h>

/* Link list node */
struct LNode
{
    int data;
    struct LNode* next;
};

/* Function to insert a node at the beginging of the linked list */
void push(struct LNode** head_ref, int new_data)
{
    /* allocate node */
    struct LNode* new_node =
        (struct LNode*) malloc(sizeof(struct LNode));
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct LNode *node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void sortedListToBST(struct LNode **head_ref, int n)
{
    /* Base Case */
    if (n <= 0)
        return;
 
    /* Recursively construct the left subtree */
    sortedListToBST(head_ref, n/2);
    *head_ref = (*head_ref)->next;
    if (*head_ref)
        cout<<(*head_ref)->data<<"  "<<n<<endl;
    sortedListToBST(head_ref, n-n/2-1);
}

/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct LNode* head = NULL;
 
    /* Let us create a sorted linked list to test the functions
     Created linked list will be 1->2->3->4->5->6->7 */
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("\n Given Linked List ");
    printList(head);
 
    /* Convert List to BST */
    cout<<endl<<endl;
    sortedListToBST(&head, 8);
  /*  struct TNode *root = sortedListToBST(head);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);*/
 
    getchar();
    return 0;
}
