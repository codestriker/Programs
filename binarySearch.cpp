#include <iostream>

using namespace std;


int arr[] = {1,2,2,2,5,6,6,9,10,10,10};

int findStartPos(int* arr, int start, int end, int n)
{
    if (start>end)
        return -1;
    
    int mid = (start + end)/2;
    
    
    if ((mid == 0 && arr[mid]==n)|| (arr[mid]==n && arr[mid-1]!=n))
        return mid;
    
    if (n <= arr[mid])
        return findStartPos(arr, start, mid-1, n);
    else
        return findStartPos(arr, mid+1, end, n);
    
    return -1;
}

int main()
{
    int size = 11;
    cout<<findStartPos(arr, 0, size-1, 2);
    getchar();
    return 0;
}
