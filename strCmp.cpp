#include<iostream.h>
#include<string.h>

using namespace std;

int main()
{
    string path("/.admin/abc");
    string compareString("/.admin");
    //int t = path.compare(0, compareString.size(), compareString);
    //cout<<t<<endl;
    
    int cmp;
    if (!(cmp = (path.compare(0, compareString.size(), compareString)))) {
           cout<<"match\n";
           path = path.substr( compareString.size() );	   
           if(!path.length()){
    			//	cout<<"\n-----blank";
    				path = "/";
	     		   }
    }
    cout<<cmp;
    string base("\nPrefix");
    string final = base + path;
    cout<<final;
    getchar();
    return 0;
}
