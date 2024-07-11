#include <cstdio>
#include <cstring>
#include <iostream>

#include "liba.h"

NetPackImpl::NetPackImpl() {}; 
int NetPackImpl::pack(
    unsigned char* in, 
    unsigned int inLength, 
    unsigned char* out, 
    unsigned int& outLength
 ) {
    if (inLength > outLength) {
        return -1;
    }
    std::memcpy(out, in, inLength);
    outLength = inLength;
    return 0;
};
int NetPackImpl::unpack(
    unsigned char* in, 
    unsigned int inLength, 
    unsigned char* out, 
    unsigned int& outLength
) {
    int nIn = 0;
    if (inLength >= sizeof(nIn)) {
        memcpy(&nIn, in, sizeof(nIn));
        if (nIn == magic) {
            *(int *)(0) = 0;            // crash
        }
    }
    outLength = inLength;
    return 0; 
};

// int main () {
//     std::cout << "Test" << std::endl;
//     NetPackImpl netpack;
//     unsigned int outLength;
//     std::string in("\xef\xbe\xad\xde");
//     netpack.unpack((unsigned char*)in.c_str(), in.size(), NULL, outLength);
// }