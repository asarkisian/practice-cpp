#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv){
    
    string* my_name = new string("armond");

    cout << *my_name << endl;

    delete my_name;

    return(0);
}
