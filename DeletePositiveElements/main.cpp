#include <iostream>
#include <vector>

using namespace std;


void delete_positive_elements(vector<int>& l){

    for(int i=l.size()-1; i>=0; --i){

        if(i%2 == 0){
            l.erase(l.begin() + i);
        }
    }

    return;
}

int main(int argc, char** argv){

    vector<int> list;

    // generate x amount of elements
    for(int i=0; i<25; i++){
        list.push_back(i);
    }

    cout << "Old List: ";
    for(int i=0; i<list.size(); i++){
        cout << list.at(i) << ", ";
    }

    delete_positive_elements(list);
    endl(cout);

    cout << "New List: ";
    for(int i=0; i<list.size(); i++){
        cout << list.at(i) << ", ";
    }
    
    return(0);
}
