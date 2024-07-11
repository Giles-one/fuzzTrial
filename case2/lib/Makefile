all: liba.so main

CXX := clang++
CXXFLAGS := -shared -fpic -fsanitize=address 

liba.so: liba.cc
	$(CXX) -o $@ $< $(CXXFLAGS) 
	strip $@

main: main.cc
	$(CXX) -o $@ $< -ggdb -L. -la -Wl,-rpath=. -fsanitize=address

clean:
	rm main liba.so
