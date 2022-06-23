#include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
 
    int a = inf.readInt(1,20000000000,"a");
    int b = inf.readInt(1,20000000000,"b");
    ensuref(a > b,"a must be strictly larger than b");
    inf.readEoln();
    
    inf.readEof();
}
