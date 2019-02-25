#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// using namespace std;

int main()
{
    std::vector<std::string> values;

    std::string word;
    while (std::cin >> word)
    {
        values.push_back(word);
    }
    
    for (std::string element : values)
        std::cout << element << std::endl;

    std::for_each ( values.begin(), 
                    values.end(), 
                    [](std::string element)
                        { std::cout << element << std::endl; }
                  );

    auto the_pos = std::find(values.begin(), values.end(), "the");
    auto big_pos = std::find_if(the_pos, values.end(), 
                                    [](std::string element)
                                        { return element.size() > 10;}
                                );
    
    std::map<std::string, unsigned> hist;
    std::for_each( the_pos, big_pos,
                   [&hist](auto element) mutable
                   {
                       ++hist(element);
                   } 
                );


}
