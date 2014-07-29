#include<iostream>

using namespace std;

bool search(int* arr, int low, int high, int x)
{
    int mid = (low + high)/2;

    if (arr[mid]==x)
        return true;

    if (low > high)
        return false;
   
    if (arr[mid] > arr[high])
    {
        if (x > arr[mid])
            low = mid+1;
        else if (x <= arr[high])
            low = mid+1;
        else
            high = mid-1;
    }
    else if (arr[mid] < arr[low])
    {
        if (x >= arr[low])
            high = mid-1;
        else if (x < arr[mid])
            high = mid-1;
        else
            low = mid+1;    
    }
    else
    {
        if (x>arr[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    
    return search(arr, low, high, x);
}

int main()
{
   // int arr[] = {3, 4, 5, 6, 7, 1, 2};
    //int arr[] =  {1, 2, 3, 4, 5, 6, 7};
    int arr[] =  {5, 6, 1, 2, 3, 4};
    //int arr = {5, 6, 7, 1, 2, 3, 4};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int x = 2;
    bool result = search(arr, 0, arrSize-1, x);
    cout<<result<<endl;
    for(int i=0; i<=arrSize; i++)
    {
        bool result = search(arr, 0, arrSize-1, i);
        cout<<result<<endl;
    }
    getchar();
    return 0;
}
