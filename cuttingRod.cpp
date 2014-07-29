#include<iostream.h>

using namespace std;

int max1(int a, int b, int c) { return std::max(a, std::max(b, c));}

int cutRod(int arr[], int size)
{
    if (size<=0)
        return 0;
    int maxVal = 0;
    for(int i=0; i<size; i++)
        maxVal = max(maxVal, arr[i] + cutRod(arr, size-i-1));
    return maxVal;
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    getchar();
    return 0;
}
