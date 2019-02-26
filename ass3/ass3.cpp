#include <regex>
#include <vector>
#include <memory>
#include <string>
#include <cstring>
#include <iostream>

// includes depending on available libraries 
// #include <optional>
// #include <filesystem>
#include <boost/optional.hpp>
#include <boost/filesystem.hpp>

class program_input
{
    public: 
        virtual ~program_input() {} // necessary to properly deallocate memory
        virtual bool read() = 0;
};

class yob_baby_name_file : public program_input
{
    public: 
    // member functions
    bool read()

    }



using all_inputs_type = std::vector<std::shared_ptr<program_input> >;

std::vector<bool> read_all_inputs(all_inputs_type& /*ai*/)
    return {}; // return a default constructed std::vector<bool>
}

std::ostream& output_usage(std::ostream& os, int /*argc*/, char *argv[])
{
    os << "Usage: " << argv[0] << " -d <directory>\n";
    return os;
}



int main (int argc, char *argv[]) 
{
    namespace fs = boost::filesystem; // using boost library on macos rather than adjust complier version
    // namespace fs = std::filesystem;
    using namespace std;

    if (argc == 1)
    {
        output_usage(cerr, argc, argv);
        return 1;
    }

    boost::optional<string> scan_directory;
    // optional<string> scan_directory;

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
    }
    
    all_inputs_type all_inputs; // hold all discovered program input files 

    for (auto& entry : fs::recursive_directory_iterator(scan_directory.value()))
    {
        cout << "DEBUG: discovered: " << entry.path() << '\n';
        if (!fs::is_regular_file(entry))
            continue;

        static regex const baby_name_file_regex( R"(yob(\d{4}).txt)" );

        smatch mr;
        string const fname = entry.path().filename().string(); // added .string() "no viable conversion..."
        if (regex_match(fname, mr, baby_name_file_regex))
        {
            cout << "DEBUG: Match found: " << fname << '\n';
        }
    }
    read_all_inputs(all_inputs);
}


