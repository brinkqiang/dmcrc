
#include "dmcrc.h"
#include <iostream>

int main( int argc, char* argv[] ) {

    static uint32_t gTable[256] = { 0 };
    int nLen = sizeof(*gTable);

    std::cout << "hello world! " << GetCRC32("hello world!") << std::endl;
    return 0;
}
