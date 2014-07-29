#include<iostream.h>

bool wildMatch(char *a, char *b)
{
    if (*a=='\0' && *b=='\0')
        return true;

    if (*b=='*' && *(b+1)=='\0')
        return true;
            
    if ((*a=='\0' && *b!='\0') || (*a!='\0' && *b=='\0'))
        return false;
    
    if ((*a!=*b) && *b!='*' && *b!='?')
        return false;
    
    if (*b=='?')
        return wildMatch(a+1, b+1);
        
    if (*b=='*')
    {
        return (wildMatch(a+1,b) || wildMatch(a, b+1));
    }
    
    return wildMatch(a+1, b+1);
}

void test(char *first, char *second)
{  wildMatch(second, first)? puts("Yes"): puts("No"); }
 
// Driver program to test above functions
int main()
{
    test("g*ks", "geeks"); // Yes
    test("ge?ks*", "geeksforgeeks"); // Yes
    test("g*k", "gee");  // No because 'k' is not in second
    test("*pqrs", "pqrst"); // No because 't' is not in first
    test("abc*bcd", "abcdhghgbcd"); // Yes
    test("abc*c?d", "abcd"); // No because second must have 2 instances of 'c'
    test("*c*d", "abcd"); // Yes
    test("*?c*d", "abcd"); // Yes
    getchar();
    return 0;
}
