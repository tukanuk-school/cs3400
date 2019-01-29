#include <iostream>
#include <cstring>

using namespace std;

const char* mymin(const char* a, const char* b)
{
  return strcmp(a,b) < 0 ? a : b;
}

template <typename T>
T mymin(T a, T b)
{
  return a < b ? a : b;
}

int main()
{
  cout 
    << mymin(2,2) << ' '
    << mymin(2.2, 2.2) << ' '
    << mymin("Hello", "World") << '\n'
  ;
}
