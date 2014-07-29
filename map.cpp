#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<int, char> numMap;
    for(char ch='a'; ch < 'm'; ch++)
        numMap[ch - 'a'] = ch;

    map<int, char>::iterator itr;
    
    itr = numMap.find(5);
    numMap.erase(itr);
    
    for(itr=numMap.begin(); itr!=numMap.end(); itr++)
        cout<<itr->second<<endl;

    cout<<endl;
    itr = numMap.find(-1);
    if (itr!=numMap.end())
        cout<<itr->first<<" "<<itr->second;
    else
        cout<<"not found"<<endl;
    
    multimap<int, int> mm;
    mm.insert(pair<int, int>(0, 1));
    mm.insert(pair<int, int>(0, 2));
    
    // http://advancedcppwithexamples.blogspot.com/2009/04/example-of-c-multimap.html
    
    getchar();
    return 0;
}
