#include <regex> // for regular expression support
#include <vector>
#include <memory> // for std::make_shared and std::shared_ptr
#include <string>
#include <cstring>  // for C's strcmp (see below)
#include <optional> // for std::optional
#include <iostream>
#include <filesystem> // for filesystem support

class program_input
{
  public:
    virtual ~program_input() {} // necessary to properly deallocate memory
    virtual bool read() = 0;
};

using all_inputs_type = std::vector<std::shared_ptr<program_input>>;

std::vector<bool> read_all_inputs(all_inputs_type& ai)

int main()
{
   
}

static regex const us_regex(R"(yob(\d{4}).txt)"); // yob literally \d digit {4} f digits .txt leterally
