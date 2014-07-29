#include<iostream.h>

class A
{
    public: 
        virtual void func() {cout<<"A"; };
};

class B: public A
{
    public:
     //   void func() { cout<<"B"; }
};

int main()
{
    B b;
    A *a = &b;
    a->func();
    getchar();
    return 0;
}
