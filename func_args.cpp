#include<iostream.h>

void func(int x, int y)
{
    cout<<x<<" "<<y;
}

void test1() { cout<<"Hi";}
void test2() { cout<<"Bye";}
void test(void* x, void* b){ };

int main()
{
    int i=0, j=0;
    func(i++, ++i);
    //printf(" %d",printf("\n%d  %d\n", ++j, j++));
    //test(test1, test2);
    getchar();
    return 0;
}
