#include<iostream.h>

#define K 3
#define J 5
char in[K+1] = "abc";
char out[J+1];

void recurse(int pos)
{
    if(pos==J)
    {
        cout<<out<<endl;
        return;
    }
    for(int i=0; i<K; i++)
    {
        out[pos] = in[i];
        out[pos+1] = '\0';
        recurse(pos+1);
    }
}

int main()
{
    recurse(0);
    getchar();
    return 0;
}
