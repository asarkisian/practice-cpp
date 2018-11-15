#include <iostream>

using std::cin;
using std::cout;
using std::endl;


double calc_feet(double in){

    return(in / 12);
}

int main(int argc, char** argv){

    double inches = 0.0;
    double feet = 0.0;
 
 
    cout << "Enter inches to convert: ";
    cin >> inches;
 
    cout << "Feet = " << calc_feet(inches) << endl; 
 
    return(0);
}
