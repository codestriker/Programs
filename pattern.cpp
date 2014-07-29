#include<iostream.h>
#include<string.h>

using namespace std;

int main() {
   
    char in[] = "*1a1b1*1*1*1c1*1d1*1*1*1*1";
    
    int len = strlen(in);
    int index = 0;
    bool set1 = false;
    bool set2 = false;

    for(int loop=0; loop<len; loop = loop+2)
    {
           if(in[loop] != '*' && in[loop] != '>') {
                in[index++] = in[loop];
                in[index++] = in[loop+1];
                set1 = false;
                set2 = false;
            }
            
            if(in[loop] == '*') {

                if (!set1) {
                    in[index++] = in[loop];
//                    loop++;
                    in[index++] = in[loop+1];
                    set1 = true;
                    set2 = false;
                                       
                }
                else {
//                    loop++;
                    cout<<loop;
                }

            }

    }
    in[index] = '\0';
    cout<<"\n\n"<<in;
    
 /*   char out[20];

    while (1) {
        int index = 0;
        int loop = 0;
        bool set1 = false;
        bool set2 = false;

        cin>>in;
        int len = strlen(in);

        while(loop <= len) {
            if(in[loop] != '*' && in[loop] != '<') {
                out[index++] = in[loop];
                set1 = false;
                set2 = false;
            }
            if(in[loop] == '<') {
                if (!set2) {
                    out[index++] = in[loop];
                    set2 = true;
                    set1 = false;
                }
            }
            loop++;    
        }

        
        cout<<out<<"\t"<<index-1<<"\n\n";
    }*/
    getchar();
    return 0;
}
