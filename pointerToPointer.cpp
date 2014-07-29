#include<iostream.h>

void func(int *&p, int *y1) {
    p = y1;
}

int main() {
    int x = 1;
    int y = 2;
    int *p = &x;
    func(p, &y);
    cout<<*p;
    getchar();
    return 0;
}
