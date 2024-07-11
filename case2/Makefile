.PHONY: all, out, fuzz, debug, clean

CXX := clang++
SRC := dataEncoder.cc

OUT := PUT
LIB := lib/liba.so
OUT_FUZZ := $(OUT)-fuzz
OUT_DEBUG := $(OUT)-debug

CXXFLAGS := -ggdb -DMAIN -fsanitize=address -Llib -la
CXXFUZZFLAGS := -ggdb -DFUZZ -fsanitize=address,fuzzer -Llib -la
CXXDEBUGFLAGS := -ggdb -DDEBUG -fsanitize=address -Llib -la
 
LDFLAGS  := -Wl,-rpath=lib

all: out fuzz debug
out: $(LIB) $(OUT) 
fuzz: $(LIB) $(OUT_FUZZ) 
debug: $(LIB) $(OUT_DEBUG) 

$(LIB):
	$(MAKE) -C lib

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $<

$(OUT_FUZZ): $(SRC)
	$(CXX) $(CXXFUZZFLAGS) $(LDFLAGS) -o $@ $<

$(OUT_DEBUG): $(SRC)
	$(CXX) $(CXXDEBUGFLAGS) $(LDFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C lib
	rm $(OUT)*