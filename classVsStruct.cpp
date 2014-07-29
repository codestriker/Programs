#include<iostream.h>

using namespace std;

struct A {
       int x;
}a;

class B {
      public:
            int x;
};

int main()
{
    B *b = new B;
    b->x = 1;
    struct A *a1;
    a1 = reinterpret_cast<struct A *>(b);
    cout<<a1->x;
    getchar();
    return 0;
}
