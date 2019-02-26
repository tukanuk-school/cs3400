#include <regex>
#include <vector>
#include <memory>
#include <string>
#include <cstring>
#include <optional>
#include <iostream>
// #include <boost/filesystem.hpp>
#include <filesystem>


class program_input
{
    public: 
        virtual ~program_input() {} // necessary to properly deallocate memory
        virtual bool read() = 0;
};

std::ostream& output_usage(std::ostream& os, int argc, char *argv[])
{
    os << "Usage: " << argv[0] << " -d <directory>\n";
    return os;
}

int main (int argc, char *argv[]) 
{
    // namespace fs = boost::filesystem; // using boost library on macos rather than adjust complier version
    namespace fs = std::filesystem;
    using namespace std;

    if (argc == 1)
    {
        output_usage(cerr, argc, argv);
        return 1;
    }



    using all_inputs_type = std::vector<std::shared_ptr<program_input> >;
    std::cout << "test";
}

// std::vector<bool> read_all_inputs(all_inputs_type& /*ai*/)
// {
//     return {}; // return a default constructed std::vector<bool>
// }

