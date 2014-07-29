#include<iostream.h>

class Base {
 public:  
  void Display() {  cout << "Base::Display() " << endl;  }	
  void setVal(int v){ cout << "Base::setVal(int) " << v <<endl; }	
  void setVal(double v){ cout<<"Base::setVal(double)"<<v <<endl;}	
};

class Derived : public Base {
 public:
  void Display(){cout << "Derived::Display() " << endl;  }	
  void setVal(char v){cout << "Derived::setVal(char)"<<v<<endl <<this<<endl;}	
};

int main() {
 Derived d;
 char c = 'A';
 d.setVal(c);     // Ok! Derived::setVal(char) A
 d.Base::setVal(65);    // Oops, Derived::setVal(char) A
 d.setVal(67.25); // Oops, Derived::setVal(char) C
 getchar();
 return 0;
}
