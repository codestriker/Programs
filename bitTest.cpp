#include <iostream.h>

using namespace std;

int main() {

    int n = 0;
    int test = n >> 31;
    cout<<test<<endl;
    n = (n & ~test) | ((~n + 1) & test); 
    cout<<n;
//    int x = (n &
   // cout<<x;
   /* signed int i = -0;
    unsigned int j = i;
    cout<<j;*/
  /*  int n = -7;
    
    int const mask = n >> (sizeof(int) * CHAR_BIT - 1);
    cout<<mask;*/
    //cout<< ((n ^ mask) - mask);
/*	int testBit = 1;
	int privs;
	
    cin>>privs;
	while( privs > testBit) {
        if(testBit & privs) {
			cout<<"\n"<<testBit;	   
           
		}
		testBit = testBit << 1;

        	
    }
testBit = testBit << 1;
	getchar();*/
		getchar();
	return 0;
}	  
