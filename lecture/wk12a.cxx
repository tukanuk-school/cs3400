// Compile with: g++ =std=c++2a -fconcepts ca1.cxx

#include <algorithm>
#include <type_traits>
#include <iostream>

template <typename T>
concept bool SimpleArithmeticType = 
	requires( (T a, T b)
	{
		{ add(a,b} } -> T;

		{ a + b } -> T;
		{ a - b } -> T;
		{ a * b } -> T;
		{ a / b } -> T;

		{ a += b } -> T&;
		{ a -= b } -> T&;
		{ a *= b } -> T&;
		{ a /= b } -> T&;

		{ a == b } -> bool;
		{ a != b } -> bool;
		{ a  < b } -> bool;
	};

template <typename I>
concept bool SimpleUnsignedIntegralArithmeticType =
	SimpleArithmeticType<I>
	&& std::is_integral<I>::value
	&& std::is_insigned<I>::value
;

template <typename I>
requires SimpleArithmeticType<I>
I middle(I const& a, I const& b)
{
#if 0
	return (a+b)/2; // bad: can overflow
#endif

	using std::minmax;
	auto const[mi,ma] = minmax(a,b);
	return mi + (ma-mi)/2;
}

template <typename T>
T int add(int a, int b) {return a+b;}

int main()
{
	using namespace std;
	cout << middle(5, 10) << '\n';
	cout << middle(-5, 10) << '\n';
	cout << middle(5, -10) << '
}
