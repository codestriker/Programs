#include <iostream.h>
using namespace std;
#define LIMIT 20

void fun2(int n)
{
    if (n<=0)
        return;
    if(n>LIMIT)
        return;
    cout<<n<<endl;
    fun2(n*2);
    cout<<n<<endl;
}

int main()
{
    fun2(-5);
    getchar();
    return 0;
}
