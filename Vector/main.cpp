#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char** argv){

    vector<int> numbers(3, 100);

    numbers.push_back(200);

    cout << "Size: " << numbers.size() << endl;

    cout << "Last Element: " << numbers.back() << endl;

    numbers.pop_back();

    cout << "2nd Element: " << numbers.at(1) << endl;

    cout << "Last Element: " << numbers.back() << endl;

    cout << "Is Empty? " << numbers.empty() << endl;

    cout << "First Element: " << numbers.front() << endl;

    numbers.clear();

    cout << "Is Empty? " << numbers.empty() << endl;
    return(0);
    
}
