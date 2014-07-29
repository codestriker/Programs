#include <iostream.h>
using namespace std;

void print (char * str)
{
  str[0] = 'X';
  cout << str << endl;
}

int main () {
  const char c[] = "sample text";
//  print ( (c) );
  print ( const_cast<char *> (c) );
  cout << c;
  getchar();
  return 0;
}
