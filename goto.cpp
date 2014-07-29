#include<iostream.h>

int main()
{
    goto err;

err:
    cout<<"1\n";
    goto err;
    return 0;
    getchar();
}
