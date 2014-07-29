#include <iostream.h>
using namespace std;

void modify(int &n) {
    n = 1;
    cout<<"hi\n";
}
    
class A {
    private:
        int n;
        void print() {
            modify(n);
            cout << n;
        }
    public:
        void print1() {
            n = 0;
            print();
        }
};


int main()
{
    A a;
    a.print1();
    getchar();
    return 0;
}
