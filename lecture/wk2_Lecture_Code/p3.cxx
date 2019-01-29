#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int twice(int i)
{
  return i*2;
}

int main()
{
  transform(
    istream_iterator<int>(cin),
    istream_iterator<int>(),
    ostream_iterator<int>(cout," "),
    twice
  );
  cout << '\n';
}

