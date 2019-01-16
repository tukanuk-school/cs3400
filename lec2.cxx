#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
    transform(
        istream_iterator<int>(cin),
        istream_iterator<int>(),
        ostream_iterator<int>(cout, " "),
        [](int i) { return i * 2; }
    );

    cout << '\n';
} //p5?