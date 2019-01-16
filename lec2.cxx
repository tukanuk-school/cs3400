#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
    string s("hello");
    transform(s.begin(), 
        s.end(), 
        s.begin(),
        [](unsigned char c) { return toupper(c); }
    );

    // std::transform(
    //     istream_iterator<int>(cin),
    //     istream_iterator<int>(),
    //     ostream_iterator<int>(cout, " "),
    //     [](int i) -> int { return i * 2; }
    // );

    cout << s << '\n';
}
