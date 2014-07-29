#include<iostream.h>

bool isSubsetSum(int set[],int N, int Sum, int tmpSum, int index)
{
    if (tmpSum == Sum)
        return true;
    if (tmpSum > Sum)
        return false;
    bool ans = false;
    for(int i=index; i<N; i++)
        ans = ans | isSubsetSum(set, N, Sum, set[i]+tmpSum, i+1);
    return ans;
}

// Driver program to test above function
int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 40;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum, 0, 0) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  getchar();
  return 0;
}
