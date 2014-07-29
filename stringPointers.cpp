#include<iostream.h>

using namespace std;

char *func(char *ptr, int *a)
{
     *a = 2;
     *ptr= 'k';
    // cout<<"\n** "<<ptr1;
     return ptr;
}

int main()
{
    char ptr[] = "hello";
    int a = 1;
    //char *ptr = "hello";
    printf("%s %d\n", ptr, a);
    printf("\n%s %d", func(ptr, &a), a);
    getchar();
    return 0;
}
