#include <iostream>

using namespace std;

int main()
{
    const int Nmax = 10;


    int n = 7; //size of input Arr;
    int Arr[] = {2, 1, 1, 4, 0, 1, 4};
    int S = 6;

    int Sum = Arr[0];
    int wR = 0, wL = 0;
    int minSize = n+10;


    while(true){// make sure that Arr[wL] and Arr[wR] are positive.
        if (Sum<=0 && wR <n){
            wR++;
            wL = wR;
            Sum = Arr[wR];
            continue;
        };

        if (Sum <=S && wR<n){
            wR++;
            Sum += Arr[wR];
            continue;
        };

        if (Sum>S){
            //cout<<wr<<endl;
            minSize = min(minSize, wR-wL);
            Sum -= Arr[wL];wL++;

            while(Arr[wL] <=0 && wL < wR){
                Sum -= Arr[wL];
                wL++;
                if (Sum>S){
                    minSize = min(minSize, wR-wL);
                }
            };
        };
        if (wR>=n-1) break;
    };

    if (minSize>n) cout <<"No solution"<<endl;
    else cout <<"minimum sequence length is "<<minSize+1<<endl;

    getchar();
    return 0;
}
