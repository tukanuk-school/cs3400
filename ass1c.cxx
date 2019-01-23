#include <iostream>
#include <iterator>
#include <string>
#include <cstring>
#include <algorithm>

// alternate method reading a line at a time

using namespace std;

int main()
{
    string str;
    // string::iterator it;

    size_t startQuote = string::npos;
    size_t endQuote   = string::npos;

    while (getline(cin, str))
    {
        startQuote = str.find("\"");
        endQuote = str.find("\"", startQuote + 1, 1);

        // cout << "sq: " << startQuote << " eq: " << endQuote << " length: " << str.length() << "\n";

        // four cases

        // no closing quote
        if (endQuote == string::npos)
        {
            transform(str.begin(), 
                str.end(), 
                ostream_iterator<char>(cout),
                [](unsigned char c) { 
                    if ( c == '.' || // period
                         c == ',' || // comma
                         c == '?' || // question mark
                         c == '-' || // dash
                         c == '\''   // single quote 
                       )
                    {
                        c = ' ';
                    } 

                    return c;
                });    
        }

        if (startQuote != string::npos && endQuote != string::npos)
        {
            // before the first "
            string beforeQuote = str.substr(0, startQuote);
            transform(beforeQuote.begin(), 
                beforeQuote.end(), 
                ostream_iterator<char>(cout),
                [](unsigned char c) {
                    if ( c == '.' || // period
                         c == ',' || // comma
                         c == '?' || // question mark
                         c == '-' || // dash
                         c == '\''   // single quote 
                        )
                    {
                        c = ' ';
                    } 

                    return c;
                });

            // between the " "
           string inQuote = str.substr(startQuote, endQuote+1 - startQuote);
           cout << inQuote; 

            // cout << "\nbq: " << beforeQuote.length() << " inq: " << inQuote.length() << "\n";

            // after the last "
            if ( str.length() > (beforeQuote.length() + inQuote.length() ) )
            {
                string afterQuote = str.substr(endQuote + 1, str.length() - endQuote);
                // cout << "afterQuote = " << afterQuote;
                transform(afterQuote.begin(), 
                    afterQuote.end(), 
                    ostream_iterator<char>(cout),
                    [](unsigned char c) {
                        if ( c == '.' || // period
                                c == ',' || // comma
                                c == '?' || // question mark
                                c == '-' || // dash
                                c == '\''   // single quote 
                            )
                        {
                            c = ' ';
                        } 

                        return c;
                    });

                cout << "\n";   
            }
        }
    cout << "\n";
    }

    cout << "\n";
}
