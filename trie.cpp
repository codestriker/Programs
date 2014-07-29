#include<iostream>
#include<string>

using namespace std;

class Trie
{
    public:
        Trie(char ch) {
            data = ch;
            isWord = false;
            for(int i=0; i<26; i++)
                next[i] = NULL;
        }
        
        bool addWord(string str);
        void print();
        void printRecv(Trie *curr, string str);
        bool searchString(Trie *curr, char *str, int len, int index);
        bool searchWildcardString(Trie *node, char *str, int len, int index);
        bool searchWildcardString1(Trie *node, char *str, int len, int index);

    private:    
        char data;
        struct Trie* next[26];
        bool isWord;
};

bool Trie::addWord(string str)
{
    int len = str.length(), startIdx=0;
    if (this==NULL)
        return false;
    Trie *node = this;
    while(startIdx<len)
    {
        char ch = str[startIdx];

        if (node->next[ch - 'a'] == NULL)
        {
            Trie *curr = new Trie(ch);
            node->next[ch - 'a'] = curr;
            if (startIdx==len-1)
                curr->isWord=true;

        }
        startIdx++;
        node = node->next[ch - 'a'];
    }
}

void Trie::printRecv(Trie* node, string str)
{
    if (node==NULL)
        return;
    if (node->isWord==true)
    {   cout<<str<<endl;
    }
    for(int i=0; i<26; i++)
    {
        if(node->next[i] != NULL)
        {
            printRecv(node->next[i], str + node->next[i]->data);
        }
    }
}
        
void Trie::print()
{
    if (this==NULL)
        return;
    string str("");
    this->printRecv(this, str);
}

bool Trie::searchString(Trie *node, char *str, int len, int index)
{
    if (index == len-1)
    {
        if (node->next[str[index] - 'a']!=NULL && node->next[str[index] - 'a']->isWord ==true)
            return true;
    }
    if (node->next[str[index] - 'a'])
    {
        return ((str[index]== node->next[str[index] - 'a']->data) &&
                (searchString(node->next[str[index] - 'a'], str, len, index+1)));
    }
    return false;
    
}

/*bool Trie::searchWildcardString(Trie *node, char *str, int len, int index)
{
    
    if (index == len-1)
    {
        if (str[index]=='.')
        {
            for(int i=0; i<26; i++)
            {
                if(node->next[i] != NULL && node->next[i]->isWord==true)
                {
                    cout<<"match";
                    return true;
                }
            }
            return false;
        }
    
        if (node->next[str[index] - 'a']!=NULL && node->next[str[index] - 'a']->isWord ==true)
            return true;
    }

    if (str[index]=='.')
    {
        for(int i=0; i<26; i++)
        {
            if(node->next[i] != NULL)
            {
                if (searchWildcardString(node->next[i], str, len, index+1))
                    return true;
            }
        }
    }
    
    else if (node->next[str[index] - 'a'])
    {
        if ((str[index]== node->next[str[index] - 'a']->data) &&
                (searchWildcardString(node->next[str[index] - 'a'], str, len, index+1)))
            return true;
    }

    return false;
}
*/
bool Trie::searchWildcardString1(Trie *node, char *str, int len, int index)
{
    
    if (index == len-1)
    {
        if (str[index]=='.')
        {
            for(int i=0; i<26; i++)
            {
                if(node->next[i] != NULL && node->next[i]->isWord==true)
                {
                    cout<<"match";
                    return true;
                }
            }
            return false;
        }
    
        else if (str[index]=='*')
            return true;

        else if (node->next[str[index] - 'a']!=NULL && node->next[str[index] - 'a']->isWord ==true)
            return true;
        
        return false;
    }

    if (str[index]=='.')
    {
        for(int i=0; i<26; i++)
        {
            if(node->next[i] != NULL)
            {
                if (searchWildcardString1(node->next[i], str, len, index+1))
                    return true;
            }
        }
    }
    else if (str[index]=='*')
    {
        if (searchWildcardString1(node, str, len, index+1))
                    return true;
        
        for(int i=0; i<26; i++)
        {
            if(node->next[i] != NULL)
            {
                if (searchWildcardString1(node->next[i], str, len, index))
                    return true;
            }
        }
    }
    else if (node->next[str[index] - 'a'])
    {
        if ((str[index]== node->next[str[index] - 'a']->data) &&
                (searchWildcardString1(node->next[str[index] - 'a'], str, len, index+1)))
            return true;
    }

    return false;
}
        
typedef struct Trie Trie;

int main()
{
    Trie *head = new Trie('\0');
    head->addWord("abc");
    head->addWord("aba");
    head->addWord("abb");
    head->addWord("babb");
    head->addWord("babbe");
    head->addWord("babc");
    head->addWord("babcde");
    //head->print();
    //char str[] = "babb";
    //cout << head->searchString(head, str, sizeof(str)/sizeof(str[0])-1, 0);
    char str[] = "*c.e";
    int strlen = sizeof(str)/sizeof(str[0]) - 1;
    cout << head->searchWildcardString1(head, str, strlen, 0);
    getchar();
    return 0;
}
