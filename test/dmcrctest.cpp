
#include "dmcrc.h"
#include <iostream>

int main( int argc, char* argv[] ) {
    std::cout << "hello world! " << GetCRC32("hello world!") << std::endl;
    return 0;
}
