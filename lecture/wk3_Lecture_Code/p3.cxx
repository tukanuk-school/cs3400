#include <algorithm>
#include <list>
#include <vector>
#include <set>
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

  set<int> s(begin(v), end(v)); // sort, remove dups [beg,end)
  multiset<int> ms(five_pos, fifteen);

  for (auto const& elem : ms)
    cout << elem << ' ';
  cout << endl;
}

