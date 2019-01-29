#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

template <typename InIter, typename OutIter, typename Func>
void mytransform(InIter first, InIter last, OutIter out, Func f)
{
  for (; first != last; ++first)
  {
    *out = f(*first);
    ++out;
  }
}

int main()
{
  mytransform(
    istream_iterator<int>(cin),
    istream_iterator<int>(),
    ostream_iterator<int>(cout," "),
    [](int i) { return i*2; }
  );
  cout << '\n';
}

