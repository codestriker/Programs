#include<iostream.h>

typedef struct B
{
    int x;
    double y;
    char z;
}b;

typedef struct A
{
    union
    {
        int a;
        b b1;
    };
}a;
int main()
{
    a a1 = {0}; 
    getchar();
    return 0;
}
