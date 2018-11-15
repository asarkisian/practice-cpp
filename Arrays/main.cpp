#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int numbers[5] = { 1, 2, 3, 4, 5 };

    cout << numbers[0] << endl;

    string names[3] = { "albert", "jim", "johnny" };

    for(int i = 0; i < (sizeof(names) / sizeof(string)); i++) {

        cout << names[i] << endl;
    }

    return(0);
}
