#include<iostream.h>

class A{
        
    public:
        A() {cout<<"constructor";};
        int x;
        int y;
        void destroy() { delete this;}
        void set(int val) { x = val;}
};

int main(){
    A a;
    A *tmp = &a;
    int *p = NULL;
    tmp->destroy();
    a.set(1);
    printf("\n%u %d %u", &a, a.x, &a.y);
    a.destroy();
    printf("\n%u %d %u", &a, a.x, &a.y);
    a.destroy();
    a.set(2);
    printf("\n%u %d %u", &a, a.x, &a.y);
    delete p;
    delete p;
    
    
    getchar();
    return 0;
}
