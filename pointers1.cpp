#include<iostream.h>

void func(const int *a,  int *b)
{
    *b = *a;
    return;
}

int main()
{
    int *p, *q, val = 1;
    p = &val;
    //*q = val - 1;
    cout<<*p<<endl;
    func(NULL, NULL);
    cout<<*q;
    getchar();
    return 0;
}
