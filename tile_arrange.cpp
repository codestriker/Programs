#include<iostream.h>

int numOfWays(int W)
{
    if(W == 0)
        return 0;
    if(W==1)
        return 1;
    if(W==2)
        return 2;
    else
    return (numOfWays(W-2) + numOfWays(W-1));
}

int main()
{
    int W=4;
    cout<<numOfWays(W);
    getchar();
    return 0;
}
