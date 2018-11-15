#include <iostream>

using std::cout;
using std::endl;


int main(int argc, char** argv){

    int a = 5;
    int *p_a = &a;

    cout << *p_a + *p_a << endl;

    return(0);
}
