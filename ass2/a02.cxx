#include <iostream>
#include <iterator>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

struct employee
{
  unsigned id;
  string name;
  double salary;
};

istream& operator >>(istream& is, employee& e)
{
  is >> e.id >> e.name >> e.salary;

  return is;
}

ostream& operator <<(ostream& os, employee const& e)
{

  os << e.id << ' ' << e.name << ' ' << e.salary;

  return os;
}

ostream& operator <<(ostream& os, vector<employee> const& v)
{
  for (auto const& e : v )
    os << '(' << e.id << ',' << e.name << ',' << e.salary << ')';
  return os;
}

int main()
{
  vector<employee> employees; // declare a sequence of employee records

  for (employee e; cin >> e; )
    employees.push_back(e);

  // abort if we did not reach the end-of-file, i.e., an error occurred...
  if (!cin.eof())
  {
    cerr << "ERROR: Invalid input. Aborting." << endl;
    return 1;
  }

  // output the employee records read in...
  cout << "     RAW_DATA: " << employees << endl;

  // create a local scope for some short-lived variables...
  {
    vector<employee> employees_copy = employees;

    stable_sort(employees_copy.begin(), employees_copy.end(), 
                [](employee const& e1, employee const& e2) 
                {
                  return e1.name < e2.name;
                }
              );
    // output data...
    cout << "      BY_NAME: " << employees_copy << endl;
  }

   stable_sort(employees.begin(), employees.end(), 
                [](employee const& e1, employee const& e2) 
                {
                  return e1.salary < e2.salary;
                }
              );
   

  // output data...
  cout << "    BY_SALARY: " << employees << endl;

  auto low_end = find_if(begin(employees), end(employees), 
                    [](employee const& e1){
                      return e1.salary > 20000;
                    });
  auto upper_end = find_if(low_end, end(employees), 
                    [](employee const& e1){
                      return e1.salary > 30000;
                    });

  for (auto i = low_end ; i != upper_end ; ++i)
    i->salary *= 1.02;
  // output data...
  cout << "SALARY_ADJUST: " << employees << endl;

  reverse(low_end, upper_end);

  // output data...
  cout << "AFTER_REVERSE: " << employees << endl;
}

