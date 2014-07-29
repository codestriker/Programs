#include<iostream.h>

void func(int *p)
{
    int x = 10;
    p = &x;
    cout << *p<<endl;
}

int main()
{
    int *p = NULL;
    func(p);
    cout<<*p;
    getchar();
    return 0;
}
