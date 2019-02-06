#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <list>
// #include <multiset>

using namespace std;

template <typename InIter>
inline void output_container(InIter pos1, InIter pos2)
{
	for_each(
		pos1, pos2,
		[](auto const& elem)
		{
			cout << elem << ' ';
		});
	cout << '\n';

}

template <typename Container>
inline void output_container(Container const& c)
{
	output_container(begin(c), end(c));
}

int main()
{
	vector<int> v;
	int i;
	while (cin >> i)	// keep going until err or eof
		v.push_back(i);

	sort(begin(v), end(v));

	// auto low_end= lower_bound(begin(v), end(v), 5);
	// auto high_end = upper_bound(low_end, end(v), 15);
	
	auto pos1 = find(begin(v), end(v), 5);
	auto pos2 = find(pos1, end(v), 15);
	
	cout << "range-based for:      ";
	for (auto const& elem : v)
		cout << elem << ' ';
	cout << '\n';

	cout << "output with for_each: ";
	output_container(pos1, pos2);

	{
		cout << "c-style for:          ";
		auto iter = pos1;	// or vector<int>::iterator iter = pos1;
		auto iterEnd = pos2;
		for ( ; iter != iterEnd ; ++iter)
			cout << *iter << ' ';
		cout << '\n';
	}

	set<int> s(pos1, pos2);
	output_container(s); cout << '\n';

	multiset<int> ms(pos1, pos2);
	list<int> l(pos1, pos2);


}
