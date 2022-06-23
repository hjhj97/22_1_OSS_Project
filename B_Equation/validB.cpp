#include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
 
    int a = inf.readInt(1,2000000000,"a");
    inf.readSpace();
    int b = inf.readInt(1,2000000000,"b");
    inf.readSpace();
    int c = inf.readInt(1,2000000000,"c");
    inf.readEoln();
    
    inf.readEof();
}
