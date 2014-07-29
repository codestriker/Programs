#include <iostream.h>
using namespace std;

class A {
};

class B : private A {
    private:
        int x;
        int func();
};

int main()
{
    A a;
    B b;
    cout<<sizeof(A) << "\t" << sizeof(b);
    getchar();
    return 0;
}
