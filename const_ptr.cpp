#include<iostream.h>

//using namespace std;

#define Z 20  // comment
enum E{ A = -1 };

class GamePlayer {
    public:
        static const int NUM_TURNS = 5;   
        static  int COUNT_TURNS;   
};

int GamePlayer::COUNT_TURNS = 6;

int main() {

    int x = 1, y = 2;
    const int *p1 = &x;
    int* const p2 = &x;
    
    p1  = &y;
    *p2 =  3;
    cout<<*p1<<*p2;

    GamePlayer g;
//    A = -2;
    cout<<"\n"<<g.NUM_TURNS<<g.COUNT_TURNS<<A<<"\t"<<Z;
    
    getchar();
    return 0;
}
