#include<iostream.h>

#define N 3

int arr[][N] = {{0, 1, 2},
                {2, 4, 8},
                {9, 1, 0}};

int sol[][N] = {0};

void printSol()
{
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            cout<<sol[i][j]<<"     ";
        cout<<endl;
    }
}

void maze(int x, int y)
{
    if (x== N-1 && y==N-1)
    {
        return;
    }
    if (x==N || y==N)
    {
        return;
    }
    
    if (x+1 < N)
    {
        if (sol[x+1][y] < sol[x][y] + arr[x+1][y])
            sol[x+1][y] = sol[x][y] + arr[x+1][y];
    }
    
    if (y+1 < N)
    {
        if (sol[x][y+1] < sol[x][y] + arr[x][y+1])
            sol[x][y+1] = sol[x][y] + arr[x][y+1];
    }

    maze(x+1,y);
    maze(x, y+1);
}

int main()
{
    maze(0, 0);
    printSol();

    getchar();
    return 0;
}
