#include<iostream.h>

int fact(int n) {
    if(n==0)
        return 1;
    return n * fact(n-1);
        
}

int main()
{
    int res = fact(4);
    cout<<res;
    getchar();
    return 0;
}
