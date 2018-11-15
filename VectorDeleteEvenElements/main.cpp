#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void deleteEvenElements(vector<int>& n){

    for(int i=0; i<n.size(); i++){

        if(i%2 == 1){

            n.erase(n.begin() + i);
        }
    }

    return;
}

void displayElements(const vector<int> n){

    for(int i=0; i<n.size(); i++){

        cout << n.at(i) << ", ";
    }

    endl(cout);

    return;
}

int main(){

    vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(7);
    numbers.push_back(8);
    numbers.push_back(9);
    numbers.push_back(10);

    deleteEvenElements(numbers);
    displayElements(numbers);

    return 0;
}
