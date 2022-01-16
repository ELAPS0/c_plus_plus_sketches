
#include <iostream>
#include "bb_str.h"

using namespace std;


bb_str foo()
{
    bb_str bb ("~~~~~~~");
    return bb;
}

int main(int argc, char* argv[])
{
    cout << "NRVO in action:"<<endl;
    bb_str bb0 = foo();
    bb0.print_info();
    cout << string('-', 80)<<endl<<endl<<endl;

    cout << "move semantic in action:"<<endl;
    bb_str bb1("*********");
    bb1 = foo();
}
