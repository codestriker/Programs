#include<iostream.h>

void parenthesis(int l, int r, int idx, char ch[])
{
    if (r<l)
    {
        //cout<<endl;
        return;
    }
    if (l>0)
    {
        ch[idx] = '(';
        ch[idx+1] = '\0';
        parenthesis(l-1, r, idx+1, ch);
    }
    if (r>0)
    {
        ch[idx] = ')';
        ch[idx+1] = '\0';
        parenthesis(l, r-1, idx+1, ch);
    }
    if (l==0 && r==0)
        cout<<ch<<endl;
}

int main()
{
    char ch[10];
    parenthesis(4, 4, 0, ch);
    getchar();
    return 0;
}
