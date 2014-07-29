#include<iostream>
#include<string>

using namespace std;

/*
int countDecodings(string str, int length, int idx)
{
    static int sum=0;
    if (length==0)
        return 0;
    
    if (idx == length || idx == length+1)
    {
        cout<<"\nFound "<<idx;
        return 1;
    }
    if (idx >= length)
        return 0;
    
 //   if (str.substr(idx, i) >= "26")
   //     return 0;
    for (int i=0; i<=1; i++)
    {
        if (str.substr(idx, i) <= "26" && idx+i<length)
        {
           sum += countDecodings(str, length, idx + i + 1);
           cout<<"\n"<<sum<<endl;
        }
        else 
            return sum;
    }
    return sum;
   // return countDecodings(str, length, idx + 1) + countDecodings(str, length, idx + 2);;
}*/

void countDecodings(string str, int length, int idx, int &res)
{
    static int sum=0;
    if (length==0)
        return ;
    
    if (idx == length || idx == length+1)
    {
        cout<<"\nFound "<<idx;
        res++;
        return;
    }
    if (idx >= length)
        return;
    
    for (int i=0; i<=1; i++)
    {
        if (str.substr(idx, i) <= "26" && idx+i<length)
        {
           countDecodings(str, length, idx + i + 1, res);
        }
    }
}

int main()
{
    string str = "1234"; int res=0;
    countDecodings(str, str.length(), 0, res);
    cout<<"\n\nResult: "<<res;
    getchar();
    return 0;
}
