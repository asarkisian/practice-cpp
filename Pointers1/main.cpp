#include <iostream>

using std::cout;
using std::endl;


int main(int argc, char** argv){

    int a = 6;
    int *b = &a;
    int **c = &b;
    int ***d = &c;

    cout << ***d << endl;

    return(0);
}
