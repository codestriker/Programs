#include<iostream.h>
#define MAX 4 // ROW-1

int arr[25] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 ,23, 24 ,25};

void print()
{
    for(int i=0; i<=MAX; i++) {
        for(int j=0; j<=MAX; j++) {
            cout<<arr[i*(MAX+1) + j]<<"  ";
        }
    cout<<"\n";
    }
}

void swap(int &a, int &b, int x, int y, int &val)
{
    int tmp;
    tmp = arr[x*(MAX+1) + y];
    arr[x * (MAX+1) + y] = val;
    a = x;
    b = y;
    val = tmp;
    
}

void swap()
{
    int val = 0;
     
    for(int i=0; i<=MAX/2; i++) {
        cout<<"\n\n";
        for(int j=i; j<=MAX-1 - i; j++){
            val = arr[i*(MAX+1) + j];
            for(int k=0; k<=3; k++) {
                //cout <<i<<" "<<j<<" -> "<<j<<" "<<MAX-i<<"\n";
                swap(i, j, j, MAX-i, val);
            }
        }
    }
}

int main()
{
    print();
    swap();
    cout<<"\n\n 90% turned matrix..\n\n";
    print();
    getchar();
    return 0;
}
        
