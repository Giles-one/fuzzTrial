#include <iostream>
#include "liba.h"

int main () {
    std::cout << "Test" << std::endl;
    
    NetPackImpl netpack;
    unsigned int outLength;
    std::string in("\xef\xbe\xad\xde");
    netpack.unpack((unsigned char*)in.c_str(), in.size(), NULL, outLength);
}
