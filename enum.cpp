#include<iostream.h>

using namespace std;

int main()
{
 	enum MyEnumType { ALPHA, BETA };
 	cout<< ALPHA<<endl;
 	cout<<sizeof(MyEnumType)<<"  "<<sizeof(ALPHA);
 	getchar();
 	return 0;
}
