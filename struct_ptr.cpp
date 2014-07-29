#include <iostream.h>
#include <stdio.h>

typedef struct{
	uint32_t	data[5];
} winreg_handle_t;

int main()
{
    winreg_handle_t *  HKey;
    winreg_handle_t  Hkey1;
    
    Hkey1.data[0]=1;
     memcpy(Hkey1, &Hkey11, sizeof(winreg_handle_t))
//    (*HKey).data[0] = 1;
    cout<<*HKey.data[0];
    getchar();
    return 0;
}
