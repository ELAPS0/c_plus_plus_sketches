
#include <iostream>
#include "bb_str.h"

using namespace std;


bb_str foo()
{
    bb_str bb0 ("pattern 0");
    return bb0;
}

int main(int argc, char* argv[])
{
    bb_str bb = foo();
    bb.print_info();
}
