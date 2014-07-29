#include<iostream>

#define N 4
using namespace std;

void distantInArray(int* arr, int val)
{
    if (val==N/2+1)
    {
        cout<<"yes\n";
        for (int i=0; i<N; i++)
            cout<<arr[i]<<"  ";
        cout<<endl;
        return;
    }
    if (val > N/2)
    {
        cout<<"No";
        return;
    }
    
    for (int i=0; i<=N-1; i++)
    {
        if (arr[i] ==0 && arr[i+val+1]==0 && (i+val+1) < N)
        {
            arr[i] = val;
            arr[i+val+1] = val;
            distantInArray(arr, val+1);
            arr[i] = 0; arr[i+val+1]=0;
        }
    }
    return;
}

int main()
{
    int arr[N];
    for (int i=0; i<=N; i++)
        arr[i] = 0;
    distantInArray(arr, 1);
    getchar();
    return 0;
}
