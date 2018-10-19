
#include "dmcrc.h"
#include "dmformat.h"
#include <iostream>

int main( int argc, char* argv[] ) {
    std::cout << fmt::format("{0} {1}", "hello world! ", GetCRC32("hello world!"));
    return 0;
}
