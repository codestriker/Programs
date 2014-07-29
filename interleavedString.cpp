#include<iostream.h>

bool isInterleaved(char *a, char *b, char *c)
{
    if (*a=='\0' && *b=='\0' && *c=='\0')
        return true;
    if (*c=='\0' && (*a!='\0' || *b!='\0'))
        return false;
    return ((*a==*c && isInterleaved(a+1, b, c+1)) ||
            (*b==*c && isInterleaved(a, b+1, c+1)));

}

// A function to run test cases
void test(char *A, char *B, char *C)
{
    if (isInterleaved(A, B, C))
        cout << C <<" is interleaved of " << A <<" and " << B << endl;
    else
        cout << C <<" is not interleaved of " << A <<" and " << B << endl;
}
 
 
// Driver program to test above functions
int main()
{
    test("XXY", "XXZ", "XXZXXXY");
    test("XY" ,"WZ" ,"WZXY");
    test ("XY", "X", "XXY");
    test ("YX", "X", "XXY");
    test ("XXY", "XXZ", "XXXXZY");
    getchar();
    return 0;
}
