#include <iostream.h>

int main()
{
    double sum = 0;
    double prevSum = 0;
    int i;
    for(i=0; i >= 0; i++)
    {
        sum += i;
        if (sum < prevSum) {
            cout <<"break "<<i<<" "<<sum<<" "<<prevSum;
            break;
        }
        prevSum = sum;
    }
    cout <<i<<" "<<sum;
    getchar();
    return 0;
}
    
