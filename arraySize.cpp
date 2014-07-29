#include<iostream.h>

void arraySize(int arr[])
{
    cout<<sizeof(arr);
}

int main()
{
    int arr[10];
    arraySize(arr);
    getchar();
    return 0;
}


