#include "testlib.h"
using namespace std;
 
int a,b,c;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    a = inf.readInt();
    b = inf.readInt();
    c = inf.readInt();
 
    int x = ouf.readInt();
    int y = ouf.readInt();
    if(a * x + b * y == c){
      quitf(_ok,"ok");
    } else if(x == -1 && y == -1){
      int ans_x = ans.readInt();
      int ans_y = ans.readInt();
      if(ans_x != -1 && ans_y != -1){
        quitf(_wa,"answer exist, but participant can't find");
      } else{
        quitf(_ok,"answer doesn't exist");
      }
    } else{
      quitf(_wa,"participant result is %d, but c is %d",a*x+b*y,c);
    }
}
