#include<iostream.h>

using namespace std;

void func(int a = 0)
{
 	 cout<<a;
}
	 
int main()
{
 	func(1);
 	func();
 	getchar();
 	return 0;
}
