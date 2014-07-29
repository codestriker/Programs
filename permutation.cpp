#include<iostream>
#include<string>

using namespace std;

static int totalPerm=1;

void swap(string& str, int i, int j)
{
    char k = str[i];
    str[i] = str[j];
    str[j] = k;
}

void permutation(string str, int start,int len)
{
    for (int front=start; front<=len; front++)
    {
        for(int exch=len; exch>front; exch--)
        {
            swap(str, front, exch);
            totalPerm++;
            //cout<<front<<"  "<<exch<<"  ";
            cout<<str<<"\n";
            permutation(str, front+1, len);
            //cout<<"unwind\n";
            swap(str, front, exch);
        }
    }
}

int main()
{
    string str = "abcdef";
    cout<<"-----------\n";
    permutation(str, 0, str.length()-1);
    cout<<"\n\nTotal permutation: "<<totalPerm;
    //cout<<str<<str.length();
    getchar();
    return 0;
}
