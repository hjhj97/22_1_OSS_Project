#include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
 
    int a = inf.readInt(1,2000000000,"a");
    inf.readSpace();
    int b = inf.readInt(1,2000000000,"b");
    ensuref(a <= b,"b must be larger or equal than a");
    inf.readEoln();
    
    inf.readEof();
}
