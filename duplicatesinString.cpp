#include<iostream>

using namespace std;

int main()
{
    char str[20];
    char hash[26] = {0};
    cin>>str;
    int curr = 0;
    int wrong = -1, swap = 0;
    while (str[curr] != '\0')
    {
        char ch = str[curr];
        if (hash[ch - 'a'] != 0)
        {
            if (wrong == -1)
                wrong = curr;
        }
        else
        {
            hash[ch - 'a'] = 1;
            if (wrong != -1)
            {
                str[wrong] = ch;
                wrong++;
                swap = 1;
            }
        }
        curr++;
    }
    str[wrong] = '\0';
    cout<<endl<<str;

    getchar();
    getchar();
    return 0;
}
