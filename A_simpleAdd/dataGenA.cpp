#include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[]) {
  registerGen(argc,argv,1);
  
  int RANGE = atoi(argv[1]);
  int a = rnd.next(RANGE);
  int b = rnd.next(a,RANGE);
  printf("%d %d\n",a,b);
 
  return 0;
}
