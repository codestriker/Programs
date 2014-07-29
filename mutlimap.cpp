#include <string.h>
#include <iostream.h>
#include <map.h>
#include <vector.h>

using namespace std;

int main() {
	map<string, string> test;
	map<string, string>:: const_iterator ii;
	vector<string> ss;
	vector<string>:: const_iterator jj;
	
	string a="af", b="bf", c="cf", d="df";
	
	test[a] = "aB" ;
	test[b] = "bB" ;

	for(ii = test.begin(); ii!=test.end(); ii++)
		   cout<<ii->first<<":"<<ii->second<<"\n";
    
    ii = test.find("af");;
    if(ii != test.end()){
        cout<<"\nFound ";
//        ss.push_back(ii->second);
    }
    else
        cout<<"\nNo";

    ss.push_back("a");		  
    ss.push_back("b");
    ss.push_back("c");
    if(ss.size() <= 0)
        cout<<"\nEmpty Vector\n";
        
    jj=ss.begin();
        
    for(jj=ss.begin(); jj!=ss.end(); jj++)
        cout<<*jj;
    
    cout<<"\n\n*** "<<ss[0];
	getchar();
	return 0;
}

