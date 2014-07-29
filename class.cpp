#include<iostream.h>
using namespace std;

class AClass{
      
      public:
          int a[2];
          AClass *next;
};
            
typedef class AClass A;
    
void fillData( A &root )
{
     root.a[0] = 0;
     root.a[1] = 1;
     root.next = new A;
     root.next-> a[0] = 2;
     root.next-> a[1] = 3;
}

class Empty { };

class NotEmpty: public Empty
{
    char t[1];
};
 
int main()
{
    Empty e;
    NotEmpty ne;
    cout<<sizeof(e)<<"  "<<sizeof(ne);
    //A root;
    //fillData(root);
    
    //cout<<root.a[0]<<root.a[1]<<root.next->a[0]<<root.next->a[1];
    getchar();
    return 0;
}
