#include<iostream.h>

int inputArr[] =  {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
int N = 10;

int doSum(int arr[], int n)
{
    int included=0, notIncluded=0, total=0;
    for (int i=0; i<n; i++)
    {
       included += inputArr[arr[i]];
    }
    for (int i=0; i<N; i++)
    {
       total += inputArr[i];
    }
    notIncluded = total-included;
    cout<<"\nincluded:"<<included<<" notIncluded:"<<notIncluded;
    return (abs(included - notIncluded));
}

void tugOfWarRecv(int N, int selectedIdxCount, int *selectedIdx, int minSum, int index, int* result)
{
    if (selectedIdxCount == N/2)
    {
        int diff = doSum(selectedIdx, N/2);
        if (diff < *result)
        {
            minSum = diff;
            *result = diff;
            cout<<"\nminSum "<<minSum;
            cout<<"  Indexes selected are:";
            for(int i=0; i<N/2; i++) cout<<inputArr[selectedIdx[i]]<<",";
            return;
        }
    }
    
    for(int i=index; i<N; i++)
    {
        selectedIdx[selectedIdxCount] = i;
        tugOfWarRecv(N, selectedIdxCount+1, selectedIdx, minSum, i+1, result);
        selectedIdx[selectedIdxCount] = 0;
    }
    return;
}
    
void tugOfWar(int n)
{
    int selectedIdx[N/2];
    for (int i=0 ; i<N/2; i++)
        selectedIdx[i] = 0;
    int result = 999999;
    tugOfWarRecv(N, 0, selectedIdx, 99999, 0, &result);
    cout<<"\n---------------\n DIFF: "<<result<<endl;
    for(int i=0; i<N/2; i++) cout<<inputArr[selectedIdx[i]]<<",";

}

int main()
{
    //int N = sizeof(arr)/sizeof(arr[0]);
    tugOfWar(N);
    getchar();
    return 0;
}
