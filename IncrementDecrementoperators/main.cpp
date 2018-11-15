#include <iostream>

using namespace std;


int main(int argc, char** argv){

    int x = 10;
    int y = 10;

    cout << "Original Value: " << x << ' ' << y << endl;
    endl(cout);

    cout << "Incremented: " << endl;
    cout << x++ << endl;
    cout << ++y << endl;

    // reset
    x = 10;
    y = 10;

    cout << "Decremented: " << endl;
    cout << x-- << endl;
    cout << --y << endl;

    return(0);
}
