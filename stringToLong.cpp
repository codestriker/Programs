#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>

using namespace std;

// checks if input string fits in the limit of Long
bool checkOverflowUnderflow(string str)
{
    string maxLongStr, minLongStr;
    
    long longMax = LONG_MAX;
    long longMin = LONG_MIN;

    // convert maximum value of long to string
    while (longMax>0)
    {
        char ch = (longMax%10 + '0');
        maxLongStr = maxLongStr + ch;
        longMax = longMax/10;
    }

    // reverse the string to get the actual value
    int idx = maxLongStr.length()-1;
    for(int i=0; i<=maxLongStr.length()/2 - 1; i++, idx--)
    {
        maxLongStr[i] = maxLongStr[i] ^ maxLongStr[idx];
        maxLongStr[idx] = maxLongStr[i] ^ maxLongStr[idx];
        maxLongStr[i] = maxLongStr[i] ^ maxLongStr[idx];
    }
    
    minLongStr = maxLongStr;
    // corect the value of long min. Add 1 to last digit.
    minLongStr[minLongStr.length() - 1] = (LONG_MAX % 10 + 1) + '0';

    cout<<"\nminLongStr: "<<"-"<<minLongStr;
    cout<<"\nmaxLongStr "<<maxLongStr<<"\n";

    // check the input string against the maximum and minimum value    
    if (str[0] == '-')
    {
        // length of input string is lesser than of the limit value
        if (str.length() - 1 < minLongStr.length()) 
        {
            return false;
        }
        // length of input string is more than the of limit value
        if (str.length() - 1 > minLongStr.length())
        {
            cout<<"\nUnderflow. String is smaller than min value of long \n";
            return true;
        }
        // length of input string is same as of the limit value. Do string comparison.
        if (str.compare(1, str.length()-1, minLongStr) > 0) // ignore '-' sign
        {
            cout<<"\nUnderflow. String is smaller than min value of long \n";
            return true;
        }
    }
    else
    {
        // length of input string is lesser than of the limit value
        if (str.length() < maxLongStr.length())
        {
            return false;
        }
        // length of input string is more than of the limit value
        if (str.length() > maxLongStr.length())
        {
            cout<<"\nOverflow. String is larger than max value of long \n";
            return true;
        }
        // length of input string is same as of the limit value. Do string comparison.
        if (maxLongStr.compare(str) < 0)
        {
            cout<<"\nOverflow. String is larger than max value of long \n";
            return true;
        }
    }

    return false;
}

// Returns converted Long value.
// On error, prints the error string and returns 0.
long stringToLong(string str)
{
    long result = 0;
    int digit = 0;
    long multiplier = 1;

    // remove leading '0's
    int pos = 0;
    for (pos=0; pos<str.length(); pos++)
    {
        if (str[pos] !='0')
            break;
    }
    string s = str.substr(pos, str.length()-pos);

    // limits check
    if (checkOverflowUnderflow(s))
        return 0;

    for (int i=s.length()-1; i>=0; i--)
    {
        digit = s[i] - '0';

        if (digit < 0 || digit > 9)
        {
            if (i==0 && s[i]== '-') // check the sign
            {
                result = result * -1;
            }
            else
            {
                cout<<"\n\n** String has invalid character '"<<s[i]<<"'";
                return 0;
            }
        }
        else
        {
            result += digit * multiplier;
            cout<<"\ndigit:"<<digit<<"  result:"<<result<<"  multiplier:"<<multiplier;

            multiplier = multiplier * 10;
        }
    }
    
    cout<<endl<<"-------------------"<<endl<<"Result: "<<result;
    cout<<endl<<"-------------------"<<endl;
    return result;
}

int main()
{
    string str;
    for (;;)
    {
        cout<<endl<<"Input string: ";
        cin>>str; 
        long i = stringToLong(str);
        cout<<endl<<endl;
    }
    
    getchar();
    return 0;
}
