#include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[]) {
  registerGen(argc,argv,1);
  
  int RANGE = atoi(argv[1]);
  int a = rnd.next(RANGE);
  int b = rnd.next(RANGE);
  int c = rnd.next(a+b,2000000000);
  printf("%d %d %d\n",a,b,c);
 
  return 0;
}
