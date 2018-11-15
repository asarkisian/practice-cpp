#include <iostream>

using std::cin;
using std::cout;
using std::endl;


double calc_inches(double ft){
    return(ft * 12);
}

int main(int argc, char** argv){

    double feet = 0.0;

    cout << "Enter feet to convert to inches: ";
    cin >> feet;

    cout << "Converted to inches: " << calc_inches(feet) << endl;

    return(0);
}
