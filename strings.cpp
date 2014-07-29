#include<iostream.h>
#include<string.h>

using namespace std;

void fun(int n, string str)
{
    if(n<0)
        return;
    str += '1';
    cout<<str<<endl;
    fun(n-1, str);
    cout<<str<<endl;
}

int main()
{
    string out = "hello1#5eD;";
    string out1 = "\\\\10.53.25.130\\ipc$";

    for (std::string::size_type i = 0; i < out.size(); ++i) {
     	out[i] = toupper( out[i] );
    }

    cout<<out;
    cout<<"\n"<<out1;
    printf("\n%s", out1.c_str());

    cout<<endl;
    string str("1");
    fun(3, str);
    getchar();
    return 0;
}
