#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "hello how are you";
    int begin=0, end=0;
    
    while(end!= std::string::npos) //-1
    {
        end = str.find(' ', begin);
        cout<<begin<<" "<<end<<" ";
        cout<<str.substr(begin, end-begin) <<endl;
        begin = end+1;
    }
    
    getchar();
    return 0;
}
