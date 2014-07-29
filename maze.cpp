#include<iostream.h>

#define N 4

int arr[][N] = {{1, 1, 1, 0},
                {1, 0, 1, 1},
                {1, 0, 0, 1},
                {1, 1, 0, 1}};

int sol[][N] = {0};

void printSol()
{
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            cout<<sol[i][j]<<"  ";
        cout<<endl;
    }
}

bool isValidMove(int x, int y)
{
    if (x==N || y==N || arr[x][y]==0)
        return false;
    return true;
}

bool maze(int x, int y)
{
    if (x== N-1 && y==N-1)
    {
        sol[x][y]=1;
        return true;
    }
    if (isValidMove(x,y))
    {
        sol[x][y] = 1;
        if (maze(x+1,y)) return true;
        if (maze(x, y+1)) return true;
        cout<<x<<":"<<y<<endl;
    }
    sol[x][y]=0;
    return false;
}

int main()
{
    if (maze(0, 0)) {
        cout<<"Found\n";
    }
    printSol();

    getchar();
    return 0;
}
