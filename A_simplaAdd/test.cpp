#include "testlib.h"
// #include <random>
using namespace std;
const int MAX_R = 2E9;
 
 
int main(int argc, char* argv[]) {
  registerGen(argc,argv,1);
  
  int n = atoi(argv[1]);
  int rightMost = atoi(argv[2]); 
  //check n <= rightMost
 
  vector<pair<int,int> > seg;
  while(n > seg.size()){
    int l = rnd.wnext(rightMost,-2); // l값이 한번에 너무 크게 나오는 걸 방지하기 위해서.
    if(seg.size() == 0) l = 0;
    int len = rnd.wnext(1,rightMost - l, -20); // 길이가 너무 길게 나오는 걸 방지하기 위해서(너무 길어지면 rightMost에 도달할 확률이 급상승함)
    int r = l + len;
    // seg.push_back(make_pair(a,b));
  }
  // random_device rd;
  // mt19937 g(rd());
  // shuffle(seg.begin(), seg.end(), g);
 
  printf("%d\n",n);
  for(auto &here : seg){
    printf("%d %d\n",here.first,here.second);
  }
  return 0;
}
