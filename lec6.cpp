#include <iostream>
#include <vector>

using namespace std;

template <typename T, int N> 
#if 0
// auto obly return: C++14 or newer
inline auto make_my_vector_with_N_default_values()
#elif 0
// traditional way all versions of c++
inline vector<T> make_my_vector_with_N_default_values()
#else 
// auto wiht -> suffix reutrnL C++11 or newer
inline auto make_my_vector_with_N_default_values() -> vector<T>
#endif
{	
	return vector<T>(N);
}

int main()
{
	auto v = make_my_vector_with_N_default_values<double,3>();	
}
