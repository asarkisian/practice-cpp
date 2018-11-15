#include <iostream>

using namespace std;

int main(int argc, char** argv){

    cout << "Variable Sizes Measured In Bytes" << endl << endl;

    int integer = 1;
    cout << "Integer: " << sizeof(integer) << endl;

    int integer_array[2] = {1,2};
    cout << "Integer Array (2 elements): " << sizeof(integer_array) << endl;

    char character = 'a';
    cout << "Character: " << sizeof(character) << endl;

    char character_array[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    cout << "Character Array (7 elements): " << sizeof(character_array) << endl;

    float single_floating = 1.0;
    cout << "Floating: " << sizeof(single_floating) << endl;

    double double_floating = 1.0;
    cout << "Double: " << sizeof(double_floating) << endl;

    bool boolean = false;
    cout << "Boolean: " << sizeof(boolean) << endl;

    return(0);
}
