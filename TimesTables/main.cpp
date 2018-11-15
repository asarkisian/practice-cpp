#include <iostream>

using std::cout;
using std::endl;


int main(int argc, char** argv){

    for(int x=0; x<10; x++){
        endl(cout);
        for(int y=0; y<10; y++){
            cout << x << '*' << y << '=' << x * y << endl;

        }
    }

    return(0);
}
