#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
 input i.e., 325 =  "300 + 20 + 5"
 input i.e., 6233 = "6000 + 200 + 30 + 3"
*/

int main(int argc, char** argv){

    string number = "";
    string converted = "";
    int zero = 0;

    cout << "Enter an integer: ";
    cin >> number;

    zero = number.length() - 1;

    for(int i=0; i<number.length(); i++){
        
        converted += number[i];

        for(int o=0; o<zero; o++){

            converted += "0";
        }

        zero = zero - 1;

        if(zero < 0){
            break;
        }

        converted += " + ";

    }

    cout << "Converted: " << converted << endl;

    return(0);
}
