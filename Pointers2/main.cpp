#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;


int main(int argc, char** argv){

    string my_name = "armond";
    string* p_my_name = &my_name;

    cout << "My name is: " << *p_my_name << endl;

    return(0);
}
