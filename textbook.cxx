#include <iostream>
// #include <locale>
#include <vector>
#include <fstream>
// #include <iterator>

using namespace std;

int main()
{
    string from, to;
    cin >> from >> to;

    ifstream istest(from.c_str());
    istream_iterator<string> ii(istest);
    istream_iterator<string> eos;

    vector<string> b(ii, eos);
    sort(b.begin(), b.end());

    ofstream os(to.c_str());
    ostream_iterator<string> oo(os, "\n");

    unique_copy(b.begin(), b.end(), oo);

    return !istest.eof() && !os;

}