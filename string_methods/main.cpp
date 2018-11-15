#include <iostream>
#include <string>

using namespace std;

int main()
{
  string full_name = "john robertson";
  string first_name; first_name.assign(full_name, 0, 5);
  string last_name; last_name.assign(full_name, 5, 2000);
  
  cout << "Full Name: " << full_name << endl;
  cout << "First Name: " << first_name << endl;
  cout << "Last Name: " << last_name << endl;
  
  cout << "Is First Name Empty? " << first_name.empty() << endl;
  
  // keep "jo" from "john"
  full_name.erase(2, 3);
  
  // insert a dash after "jo"
  full_name.insert(2, "-");
  
  // keep "ro" from "robertson"
  full_name.erase(5, 999);
  cout << "Modified Full Name: " << full_name << endl;

  // clear entire string
  full_name.clear();
  
  return(0);
}
