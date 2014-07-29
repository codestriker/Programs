#include<iostream.h>

using namespace std;

class A {
public :
	  A() { cout<<"\nA constructor "; print(); }
	  int x;
	  virtual void print(){ cout<<"\nnooo\n"; }
};

class B: public A{
public :
	   //	  B(int x) { cout<<"\nB constructor "<<x; }
	   void print(){ cout<<"\nYes "<<y; }
	   int y;
};	  

int main()
{
 	B a;
   a.print();
 	getchar();
 	return 0;
}
