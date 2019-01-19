#include <iostream>

using namespace std;

int main()
{ 
  bool is_within_double_quotes = false;

// Use all but one of these "METHOD"s and delete the rest...
#if METHOD == 1
  // skipws using IO manipulator noskipws...
  char byte; 
  while (cin >> noskipws >> byte)
#elif METHOD == 2
  // skipws by turning off all skipping of whitespace for cin...
  cin.unsetf(ios_base::skipws);
  char byte; 
  while (cin >> byte)
#else
  // skipws using unformatted input...
  // NOTE: Using a char here is important if one wants to write cout << byte
  //       since the return from .get() is not a char.
  for (char byte = cin.get(); cin; byte = cin.get())
#endif
  { 
    #error "Write code in here to process the input and write output to std::cout."
  }
}
