#ifndef LIBA_H
#define LIBA_H

extern int magic;

class NetPack {
public:
    virtual int pack(unsigned char* in, unsigned int inLength, unsigned char* out, unsigned int& outLength) = 0;
    virtual int unpack(unsigned char* in, unsigned int inLength, unsigned char* out, unsigned int& outLength) = 0;
    virtual ~NetPack() {}
};

class NetPackImpl: public NetPack {
public:
    NetPackImpl(); 
    NetPackImpl(const int magic);
    int pack(unsigned char* in, unsigned int inLength, unsigned char* out, unsigned int& outLength) override;
    int unpack(unsigned char* in, unsigned int inLength, unsigned char* out, unsigned int& outLength) override;
};
#endif