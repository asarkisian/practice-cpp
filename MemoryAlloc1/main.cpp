#include <iostream>

using std::cout;
using std::endl;


int main(int argc, char** argv){

    int *a = new int(5);

    cout << *a << endl;

    delete a;

    return(0);
}
