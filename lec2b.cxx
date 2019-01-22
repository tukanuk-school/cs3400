#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int test(istream_iterator c);

int main()
{
    // string s("hello");
    // transform(s.begin(), 
    //     s.end(), 
    //     s.begin(),
    //     [](unsigned char c) { return toupper(c); }
    // );

    std::transform(
        istream_iterator<char>(cin),
        istream_iterator<char>(),
        ostream_iterator<char>(cout, " "),
        test(cin)
    );

    // cout << s << '\n';
    cout << '\n';
}

int test( char c) {
    cout << c;
}