#include<iostream.h>
#include<string.h>

char str[] = "abcd";

void print(int start, int end)
{
    for(int i=start; i<=end; i++)
        cout<<str[i];
    cout<<endl;
}

void allWords(int start, int end, int len)
{
    if(start>=len)
        return;
        
    if(end>=len) {
        end = 0;
        start++;
    }
    print(start, end);
    allWords(start, end+1, len);
    
}

int main()
{
    int len = strlen(str);
    allWords(0, 0, len);
    
    getchar();
    return 0;
}
