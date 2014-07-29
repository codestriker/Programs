#include<iostream.h>

using namespace std;

struct A{
	   char b[4];
   	   int a;
	   };
	   
int main() {
	struct A a;
	struct A* pA = &a;
    char *p = (char *)pA;
	a.b[0]='a';
	a.b[1]='b';
	a.b[3]='c';
	a.b[3]='d';

    cout<<p[0]<<p[1];
    getchar();
    return 0;
}
