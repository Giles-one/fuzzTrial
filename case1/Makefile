.PHONY: run, clean

OUT := PUT
CXX := clang++

# CXXFLAGS := -fsanitize=address -Llib -la
CXXFLAGS := -Llib -la
LDFLAGS  := -Wl,-rpath=lib

$(OUT): dataEncoder.cc
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm $(OUT)
