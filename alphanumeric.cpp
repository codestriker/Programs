#include<iostream.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int main()
{
    char str[10];
    cin >> str;
    int len = strlen(str);
    cout<<len<<endl;
    for(int i=0; i< len; i++)
    {
            if( !isalnum(str[i]) && (str[i] != '/'))
            {
                cout<<endl<<i<<" No\n";
                break;
            }
    }
    cout << "yes";
    getchar();
    getchar();
    return 0;
}
