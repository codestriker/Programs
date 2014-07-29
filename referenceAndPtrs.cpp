#include<iostream>
using namespace std;

struct Tree{
    int x;
    int y;
};

void fun(struct Tree &t)
{
    cout<<t.x;
}

int main()
{
    Tree newTree;
    newTree.x = -1;
    struct Tree *pTree = NULL;
    fun(*pTree);
    getchar();
    return 0;
}
