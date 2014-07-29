#include<iostream>

using namespace std;

#define N 10

struct Node
{
    int data;
    Node* next;
};


class Hash
{
    public:
        Node* list[N];
        
        Hash() 
        {
            for(int i=0; i<N; i++)
                list[i] = NULL;
        }
        
        Node* newNode(int num)
        {
            Node *tmp = new Node;
            tmp->data = num;
            tmp->next = NULL;
            return tmp;
        }
        void insert(int num);
        void search(int num);
};

void Hash::insert(int num)
{
    Node *hashArr = list[num % N];
    if (hashArr == NULL)
    {
        list[num % N] = newNode(num);
    }
    else
    {
        Node *node = newNode(num);
        Node *ptr = hashArr->next;
        hashArr->next = node;
        node->next = ptr;
    }
}

void Hash::search(int num)
{
    Node *hashArr = list[num % N];
    bool found = false;
    if (hashArr == NULL)
        cout<<"\nBucket empty for "<<num;
    else
    {
        while(hashArr)
        {
            if (hashArr->data == num)
            {
                cout<<"\nFound "<<num<<" in bucket "<< num%N<<endl;
                found = true;
                break;
            }
            else
            {
                hashArr = hashArr->next;
            }
        }
        if (!found)
            cout<<"\nNOT Found "<<num<<" in bucket "<< num%N<<endl;
    }
}

int main()
{
    Hash *hash = new Hash;
    hash->insert(1);
    hash->insert(11);
    hash->insert(21);
    hash->insert(31);
    hash->insert(41);
    hash->insert(5);

    hash->search(2);
    hash->search(21);
    hash->search(41);
    hash->search(5);
    hash->search(61);
    hash->search(31);
    
    getchar();
    return 0;
}
    
