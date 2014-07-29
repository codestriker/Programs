#include<iostream.h>
#include<vector.h>
#include<set.h>

using namespace std;
int main()
{
    int a=1, b=23, c=456;
    std::vector<int> vect(5);
    std::set <vector<int> > myset;
    std::set <vector<int> >::iterator it;
    
    std::vector<int> vect1(5);

    vect[0] = b;
    vect[0] = a;
    vect[1] = b;
    vect[2] = c;

    vect1[0] = a;
    vect1[1] = b;
    vect1[2] = c;

    myset.insert(vect);
    it=myset.find(vect1);
    
    if( it == myset.end())
        cout<< "not found";
    else
        cout <<"found ";
    getchar();
    return 0;
}
