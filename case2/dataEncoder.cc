#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>

#include "dataEncoder.h"

int TestOneInput(uint8_t *data, size_t size) {
  unsigned int fakeNum;
  fakeObj *obj = new fakeObj; 
  obj->filed0 = 0;
  obj->filed1 = 1;
  obj->filed2 = 2;
  obj->filed3 = 3;
  API fuzzAPI = (API)(NetPackImpl::unpack);
  fuzzAPI(obj, data, size, (unsigned char*)(NULL), fakeNum);
  delete obj;
  return 0;
}

#ifdef FUZZ
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  TestOneInput((uint8_t*)(data), size);
  return 0;
}
#endif

#ifdef MAIN
int main () {
  unsigned char payload[] = {
    0xef, 0xbe, 0xad, 0xde
  };
  TestOneInput(payload, sizeof(payload));
}
#endif

#ifdef DEBUG
int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " /path/to/testcase" << std::endl;
    return -1;
  }
  
  char payload[4096];
  char* filePath = argv[1];
  
  int fd = open(filePath, O_RDONLY);
  int count = read(fd, payload, 4096);
  if (count <= 0) {
    std::cerr << "Error in read()" << std::endl;
    return -2;
  }

  TestOneInput((uint8_t*)payload, count);
  return 0;
}
#endif
