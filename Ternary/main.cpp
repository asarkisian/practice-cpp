#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char** argv){

    int a = 5;
    int b = 10;
    int c;

    c = (a < b) ? a : b;
    cout << "C = " << c << endl;

    c = (a >= b) ? a : b;
    cout << "C = " << c << endl;

    return(0);
}
