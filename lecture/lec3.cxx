#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    list<int>l;
    for (int i ; cin >> i; )
    {
        l.push_back(i);

        auto five_pos = find(begin(l), end(l), 5);
        auto fifteen = find(five_pos, end(l), 15);

        transform(
            five_pos, fifteen,   // input [five_pos, fifteen]
            five_pos,            // start output at five_pos
            [](auto const& value)
            {
                return -value;
            }
        );
    
        for (auto const& elem : l)
            cout << elem << ' ';
        cout << endl;
    }
}