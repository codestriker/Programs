#include<iostream>

using namespace std;
int main()
{
    string str = "aabbbbbbbbbbbbcccdeffffgg";
    
    int j = 0;
    int count = 0;
    int put = 0;
    for(int i=1; i<=str.length(); i++)
    {
        if (str[j] == str[i])
            count++;
        else
        {
            cout<<"\nput:"<<put<<"  count:"<<count<<"  j:"<<j<<"  i:"<<i;
            str[put++] = str[j];
            str[put++] = '0' + count+1;
            j = i;
            count = 0;
        }
    }

    str[put] = '\0';
    cout<<"\n\n"<<str.c_str();
    
    getchar();
    return 0;
}
