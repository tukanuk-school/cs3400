#include <regex>
#include <vector>
#include <memory>
#include <string>
#include <cstring>
#include <optional>
#include <iostream>
// #include <boost/filesystem.hpp>
#include <filesystem>

using all_inputs_type = std::vector<std::shared_ptr<program_input> >;

std::vector<bool> read_all_inputs(all_inputs_type& /*ai*/)
{
    return {}; // return a default constructed std::vector<bool>
}


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

    optional<string> scan_directory;

    for (int args_pos = 1 ; args_pos < argc ; ++args_pos)
    {
        if (!strcmp(argv[args_pos], "-d") )
        {
            if (args_pos + 1 >= argc)
            {
                output_usage(cerr, argc, argv) << "\tNOTE: The -d option appreas without a <directory> argument.\n";
                return 2;
            }

            // assign argv to directory
            ++args_pos;
            scan_directory = argv[args_pos];
        }
        else
        {
            output_usage(cerr, argc, argv) << "\tNOTE: Invalid argrument(s) provided.\n";
        }

        all_inputs_type all_inputs; // hold all discovered program input files 

        for (auto& entry : fs::recursive_directory_iterator(scan_directory.value()))
        {
            cout << "DEBUG: discovered: " << entry.path() << '\n';
        }
        read_all_inputs(all_inputs);
    }
}


