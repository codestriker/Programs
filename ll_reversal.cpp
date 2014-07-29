#include<iostream.h>

struct linkedList{
    int data;
    struct linkedList *next;
};

typedef struct linkedList ll;
    
void createLL(ll **head)
{
    ll *curr= NULL, *temp = NULL;
    *head = new ll;
    curr = *head;
    curr->data = 0;
    curr->next = NULL;
    
    for(int i=1; i<5; i++)
    {
        temp = new ll;
        curr->next = temp;
        temp->data = i;
        temp->next = NULL;
        curr = temp;
    }
    cout<<"created\n";
}

void printLL(ll **head)
{
    cout<<"\nPrinting...";
    ll *curr = *head;
    while (curr) {
        cout << curr->data <<" ";
        curr = curr->next;
    }
    cout<<"\nPrinted";
}

void reverseLL(ll *curr)
{
    if (curr == NULL){
        cout<<"\nReverse ... ";
        return;
    }
    else {
        reverseLL(curr->next);
    }
    
    cout<<" "<<curr->data<<" ";
    return;       
}

int main()
{
    ll *head, *printHead;
    createLL(&head);
    printLL(&head);
    printHead = head;
    reverseLL(printHead);
    getchar();
    return 0;
}
    
