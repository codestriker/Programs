#include<iostream.h>
using namespace std;


struct A{
	   char a ;
	   char b ;
	   int c ;
};

class X{
    private:
        struct {
            int x;
            int y;
        }B;
    
    public:
        X();
        int z;
};

X::X()
{
    B x = {0};
}

int main() {

	/*struct A a;
	a.a = 'a';
	a.b = 'b';
	int *p = (int *)&a;
	int x=1, y=1;
	x &= ~y;
	cout<<x<<"\n";
	cout<<sizeof(a);
	cout<<p<<"\t"<<p+1;	
	cout<<"\n"<<*p<<"\t"<<*(p+1);*/
	X x;
	cout<<sizeof(X);
	getchar();
	return 0;
}
