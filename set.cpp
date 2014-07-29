// set::insert (C++98)
#include <iostream.h>
#include <set.h>

int main ()
{
    std::set<int[5]> myset;
    int i = 0;
    
    int arr[5];
    for(i=0; i<5; i++)
    {
        arr[i] = i;
    }
    myset.insert(arr);
    getchar();
    return 0;
}
