all: liba.so main

CXX := g++
CXXFLAGS := -shared -fpic

liba.so: liba.cc
	$(CXX) -o $@ $< $(CXXFLAGS) 
	strip $@

main: main.cc
	$(CXX) -o $@ $< -ggdb -L. -la -Wl,-rpath=. 

clean:
	rm main liba.so