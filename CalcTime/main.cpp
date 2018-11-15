#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int calc_days(int year){

    return(year * 365);
}


int calc_hours(int year){

    return(year * 365 * 24);
}


int calc_minutes(int year){

    return(year * 365 * 24 * 60);
}


int calc_seconds(int year){

    return(year * 365 * 24 * 60 * 60);
}

int main(int argc, char** argv){

    int year = 0;

    cout << "Enter year(s): ";
    cin >> year;
    
    cout << "Converted to days is: " << calc_days(year) << endl;
    cout << "Converted to hours is: " << calc_hours(year) << endl;
    cout << "Converted to minutes is: " << calc_minutes(year) << endl;
    cout << "Converted to seconds is: " << calc_seconds(year) << endl;
    
    return(0);
}
