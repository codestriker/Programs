#include<iostream.h>

int *p;

const int * func()
{
    return p;
}

int main() {
    const int *q = NULL;
    p = new int[8];
    q = func();
    delete[] q;
    getchar();
    return 0;
}
    
