#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string,unsigned> freq_hist;

int main()
{
  string i;
  while (cin >> i)
    ++freq_hist[i];

  for (auto const& entry : freq_hist)
  {
    cout << "Entry: " << entry.first << ", "
      << entry.second << '\n';
  }
}

