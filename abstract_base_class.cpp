#include <iostream.h>

class AbstractBase {
 public:
  AbstractBase() { std::cout << "Base Ctor" << "\n"; }
  virtual ~AbstractBase() = 0;
  virtual int Area() = 0;
  
};

 AbstractBase :: ~AbstractBase() { cout<< "Base destr\n";};

class Derived : public AbstractBase {
 public:
  Derived() { std::cout << "Derived Ctor" << "\n"; }
  ~Derived() { std::cout << "Derived Dtor" << "\n"; }
  int Area() {}
};

int main() {    
     { Derived d;  }
     getchar(); 
     return 0;
} 
