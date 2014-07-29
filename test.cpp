#include<iostream.h>

struct A {
    int x;
    int *y;
};

void fun(int *p)
{
    int x = 10;
    p = &x;
}

int main()
{
    /*A *a;
    a->x = 1;*/
    int *p;
    fun(p);
    cout<<*p;
    getchar();
    return 0;
}
