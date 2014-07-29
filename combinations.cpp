#include<iostream.h>

#define K 5
#define J 3
char in[K+1] = "12345";
char out[J+1];

void recurse(int pos, int start)
{
    if(pos==J)
    {
        cout<<out<<endl;
        return;
    }
    for(int i=start; i<start+J-1; i++)
    {
        out[pos] = in[i];
        out[pos+1] = '\0';
        recurse(pos+1, i+1);
        start = pos+1;
    }
}

int main()
{
    recurse(0, 0);
    getchar();
    return 0;
}
