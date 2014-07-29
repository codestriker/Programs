#include<iostream.h>
#include<string.h>

using namespace std;

void strcpy(char *s, char *t) {
    while((*s++ = *t++)) ;
    cout<<"Cpy "<<s<<"\n";
}
    
int main() {
 
    int *p;
    int x = 1;
    p = &x;
    printf("%u\t%u\t%u\t%u\n", *p, &p, p, &x);

    int *q = NULL;
    printf("%u\t%u\t\n", q, &q);
    
    char abc[] = "abcde";
    char pqr[] = "pqrst";
    char *s = abc;
    char *t = pqr;

//    s++;
//    cout << *s <<"\t" << s <<endl;

    strcpy(s, t);
    cout << s <<"\t" << t <<endl;
    
    getchar();
    return 0;
}
