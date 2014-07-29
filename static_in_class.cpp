#include <iostream.h>

class A
{
    public:
         const static double var = 10.30;
};

//int A::var = -1;

int main()
{
    cout<< A::var;
    getchar();
    return 0;
}
