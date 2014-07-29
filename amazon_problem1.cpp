#include<iostream>

using namespace std;

void divide(int den, int num)
{
    // this variable will help us to set the sign of quotient
    int sign = 1;

    cout<<endl<<num<<"/"<<den;

    // if any of the input is negative, make it positive and toggle the sign var.
    if (den<0)
    {
        sign = sign * -1;
        den = den * -1;
    }
    if (num<0)
    {
        sign = sign * -1;
        num = num * -1;
    }

    // error condition
    if (den==0)
    {
        cout<<"\nDenominator is zero. Result is infinity"<<endl<<endl;
        return;
    }

    // we know, numerator = quotient*denominator + modulus 
    // keep subtracting denominator from numerator till numerator is greater.
    int count = 0;
    while (num>=den)
    {
        num = num - den;
        count++;
    }

    // Change the result depending on the value of sign.
    cout<<"\nQuotient: "<<count*sign<<endl<<endl;
    return;
}

int main()
{
    int num, den;
    cout<<"Enter numerator: ";
    cin>>num;
    cout<<"Enter denominator: ";   
    cin>>den;
    divide(den, num);
    /* testing
    divide(1, 1);
    divide(1, 10);
    divide(10, 1);
    divide(2, 33);
    divide(33, 2);
    divide(5, 0);
    divide(0, 5);
    divide(-20, -3);
    divide(-3, 20);
    divide(-20, 3);
    divide(20, -3);
    divide(200000, 400);
    divide(2000, 400000);
    divide(2000, 4000000000000000000000); // compiler catches this error. "integer constant too large for long type".
    */
    getchar();
    getchar();
    return 0;
}
