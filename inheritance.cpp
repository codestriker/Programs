#include<iostream>
#include<string>

using namespace std;

class A
{
    protected:
        int data;
};

class B: public A
{
    public:
        A *root;
    public:
        void fun() { data = 0;}
        void print() { cout<<data;}
};

int main()
{
    string s = "000000011000";
    int i = 0;
    for (i=0; i<s.length(); i++)
    {
        if (s[i] !='0')
            break;
    }
    
    cout<<str;

    B b;
    b.fun();
    b.print();
    getchar();
    return 0;
}
