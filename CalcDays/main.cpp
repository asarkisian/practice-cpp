#include <exception>
#include <iostream>
#include <stdexcept>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::exception;

int calc_days(int yr){
    return(yr * 365);
}


int main(int argc, char** argv){

    try{

        int years = 0;

        cout << "Enter number of years: ";
        cin >> years;
        
        cout << "Converted to days: " << calc_days(years) << endl;
    
    }
    catch(const exception& e){

        cerr << e.what() << endl;
    }
    catch(...){

        cerr << "Unknown error has occurred!" << endl;
    }


    return(0);
}
