#include<ctype.h>
#include<string.h>
#include<iostream.h>

using namespace std;

int main()
{
 	string s;
 	while(1){
    cin>>s;
 	const char* str = s.c_str();
	while (*str) {
        if(strchr("`~$%^&_},!{.-", *str) == NULL && (isalnum(*str))==0) {
            cout<<"No\n";
        }
        ++str;    
    }
    cout<<"\nYes\n";
	}
	getchar();
		getchar();
	return 0; 							
}
