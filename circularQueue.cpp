#include<iostream.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

void enqueue(Node **front, Node **rear, int n)
{
    Node *tmp = new Node;
    tmp->data = n;
    tmp->next = *front;
    if (*front == NULL)
        *front = tmp;
    if (*rear)
        (*rear)->next = tmp;
    *rear = tmp;
}

void print(Node **front, Node **rear)
{
    if (*front==NULL || *rear == NULL)
        return;
    Node *curr = *front;
    while(curr != *rear)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

void dequeue(Node **front, Node **rear)
{
    if (*front==NULL || *rear == NULL)
        return;
    if (*front == *rear)
    {
        cout<<"\nPop "<<(*front)->data;
        front = rear = NULL;
    }
    Node *tmp = *front;
    cout<<"\nPop "<<(*front)->data;
    *front = (*front)->next;
    (*rear)->next = front;
    delete tmp;
}

int main()
{
    Node *front = NULL, *rear = NULL;
    //*front = NULL, *rear = NULL;
    for(int i=1; i<=10; i++)
        enqueue(&front, &rear, i);
   // cout<<(*front)->data<<(*rear)->data;
    print(&front, &rear);
    for(int i=1; i<=5; i++)
        dequeue(&front, &rear);
    cout<<endl;
    print(&front, &rear);
    getchar();
    return 0;
}
