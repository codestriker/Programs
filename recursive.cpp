#include<iostream.h>

void print()
{
    static int i = 0;
    i++;
    if(i>5)
        return;

    print();
        cout<<i << endl;
}
    
int main()
{
    print();
    getchar();
    return 0;
}
