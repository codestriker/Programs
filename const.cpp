#include<iostream.h>

using namespace std;

void check(int a)
{
    cout<<"\nCheck func\n";
}

int main(){
    static const int a = 1;
    int b;
    b = a;
    cout<<b;
    b = 2;
    cout<<b;
    check(a);
    getchar();
    return 0;
}
