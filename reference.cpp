#include<iostream.h>

   
int main()
{
    int arr[][2] = { {1,2}, {2,3 } };
    int x = 1;
    int &ref = x;
    ref++;
    cout<<x<<"  "<<ref<<endl;
    
    int y = 10;
    ref = y;
    ref++;
    cout<<y<<"  "<<ref;
    getchar();
    return 0;
}
