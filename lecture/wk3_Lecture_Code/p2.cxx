#include <algorithm>
#include <list>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
  list<int> l;
  for (int i; cin >> i; )
    l.push_back(i);

  auto five_pos = find(begin(l), end(l), 5);
  auto fifteen = find(five_pos, end(l), 15);

  vector<int> v;
  transform(
    five_pos, fifteen, // input [five_pos,fifteen)
    back_inserter(v),  // append transformed elements to v
    [](auto const& value)
    {
      return -value;
    }
  );

  for (auto const& elem : v)
    cout << elem << ' ';
  cout << endl;
}

