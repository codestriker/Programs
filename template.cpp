#include <iostream.h>

template<class T>
void func(T arg)
{
    T tmp;
    tmp = (T)3/2;
    cout<<tmp<<"\t";
    cout<<arg/tmp<<endl;
}
/*
template void func<double>(int);
*/
template void func<char>(char);


void test(int y=0,int x=0)
{
    cout<<"\nHHHHHH "<<y<<endl;
}

int main()
{
    func(5);
    //func<double, int>(5);
    test(1);
    getchar();
    return 0;
}
