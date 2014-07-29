#include<iostream.h>

class A {
    private:
        int uid;
    public:
        A(int u):uid(u) { }
        const int& getSessionId() const { return  uid; }
};

int main()
{
    A a(1);
    int x = 5;
    int *p = NULL;
    while (p) { cout<<"TEST\n";}
    
    if(a.getSessionId() > 0) {
        cout<<"YES";
    }
    getchar();
    return 0;
}
