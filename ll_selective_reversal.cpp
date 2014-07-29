#include<iostream.h>

#define N 6
#define K 3

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node LlNode;

LlNode* createNode(int n)
{
    LlNode* tmp = new LlNode();
    tmp->data = n;
    tmp->next = NULL;
    return tmp;
}
        
void create(LlNode **head)
{
    *head = createNode(N);
    for(int i=N-1; i>0; i--)
    {
        LlNode *tmp = createNode(i);
        tmp->next = *head;
        *head = tmp;
    }
}

void print(LlNode **node)
{
    LlNode *head = *node;
    while(head)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
}

void reverse(LlNode **head, LlNode *tmp)
{
    if (tmp == NULL)
        return;
    if(tmp->next==NULL)
    {
        (*head)->next = NULL;
        *head = tmp;
        return;
    }
    Node *prev = tmp->next;
    reverse(head, tmp->next);
    prev->next = tmp;
        
}

void reverseSelective(LlNode **head, LlNode *tmp, LlNode **end, LlNode *start, int n)
{
    if(n==0 || tmp->next==NULL)
    {
        // this is end of the reversed list. This will be the starting point when we call this routine for next set of K.
        *end = *head;
        
        // this will be used to connect 2nd reversed list with previous list
        if (start)
            start->next = tmp;

        // adjust pointers before we starting rewinding
        (*head)->next = tmp->next;
        *head = tmp;
        return;
    }

    Node *prev = tmp->next;
    reverseSelective(head, tmp->next, end, start, n-1);
    prev->next = tmp;
        
}

void reverseSelectiveMain(LlNode **head)
{
    LlNode *end = NULL;
    LlNode *prev = NULL;
    reverseSelective(head, *head, &end, prev, K-1);
    prev = end;
    end=end->next;
    if (end)  cout<<"Hi"<<end->data;
    reverseSelective(&end, end, &end, prev, K-1);
}

int main()
{
    struct Node *head = NULL;
    create(&head);
    print(&head);
    //reverseSelective(&head, head, 3-1);
    reverseSelectiveMain(&head);
    //reverse(&head, head);
    cout<<"\n\nReverse\n";
    print(&head);
    getchar();
    return 0;
}
