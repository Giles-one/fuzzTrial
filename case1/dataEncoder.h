// NetPackImpl::unpack(unsigned char*, unsigned int, unsigned char*, unsigned int&)
namespace NetPackImpl {
  int unpack(unsigned char*, unsigned int, unsigned char*, unsigned int&);
};

typedef void (*API)(void *, unsigned char*, unsigned int, unsigned char*, unsigned int&);

struct fakeObj {
  unsigned long filed0;
  unsigned long filed1;
  unsigned long filed2;
  unsigned long filed3;
};