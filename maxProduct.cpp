#include<iostream.h>

int max1(int a, int b, int c) { return std::max(a, std::max(b, c));}


int maxProd(int N)
{
    if (N<=1)
        return 0;
    int maxVal = 0;
    for (int i=1; i<N; i++)
        maxVal =  max1(maxVal, i * (N-i), maxProd(N-i)*i);
    return maxVal;
}

/* Driver program to test above functions */
int main()
{
    cout << "Maximum Product is " << maxProd(10);
    getchar();
    return 0;
}
