#include <iostream>

using namespace std;

int twice(int i)
{
  return i*2;
}

int main()
{
  int i;
  while (cin >> i)
    cout << twice(i) << ' ';
  cout << '\n';
}

