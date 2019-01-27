#include <iostream>

using namespace std;

int main()
{ 
    bool is_within_double_quotes = false;

    char byte; 
    while (cin >> noskipws >> byte)
    {
        if ( byte == '\"')  // quotation mark
        {
            is_within_double_quotes = !is_within_double_quotes;
        }
        
        if (!is_within_double_quotes)
        {
            if ( byte == '.' || // period
                 byte == ',' || // comma
                 byte == '?' || // question mark
                 byte == '-' || // dash
                 byte == '\''   // single quote 
               )
            {
                byte = ' ';
            } 

        } 
        
        cout << byte;
    }
}
