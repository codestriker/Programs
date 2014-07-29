#include<iostream>

using namespace std;
 
/* A linked list node */
struct node
{
    int data;
    struct node *next;
};


void rearrange(struct node *node, struct node *start)
{
    if (node==NULL)
        return;
    
    rearrange(node->next, start);
    static struct node *temp = start;
    cout<<"\n"<<temp->data<<"  "<<node->data;
    temp->data = node->data - temp->data;
    temp  = temp->next;
}

/* Function to add a node at the beginning of Linked List */
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Druver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling  rearrange() ");
    printList(start);
 
    // skip half list
    rearrange(start->next->next->next, start);
 
    printf("\n\n Linked list after calling  rearrange() ");
    printList(start);
 
    getchar();
    return 0;
}
