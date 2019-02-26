CXX=clang++
CXXFLAGS=-std=c++17 -Wall -Wextra
LDFLAGS=

all: lec6

clean:
	rm -vf 

a03: lec6.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
