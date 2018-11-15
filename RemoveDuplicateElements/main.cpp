#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::vector;


void display_list(const vector<int> l){

    endl(cout);

    for(unsigned int i=0; i<l.size(); i++){
        cout << l.at(i) << endl;
    }

    endl(cout);
}


void remove_duplicates(vector<int>& l){

    vector<int> temp;

    for(int x=l.size()-1; x>=0; x--){

        for(int y=l.size()-1; y>=0; y--){

            if(x != y){
                if(l.at(x) == l.at(y)){
                    l.erase(l.begin() + x);
                }
            }
        }
    }
}

int main(int argc, char** argv){

    vector<int> list;

    try{

        list.push_back(4);
        list.push_back(3);
        list.push_back(6);
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        list.push_back(1);
        list.push_back(4);
        list.push_back(2);
        list.push_back(5);
        list.push_back(7);

        display_list(list);

        remove_duplicates(list);

        display_list(list);
    }
    catch(const exception& e){
        cerr << e.what();
    }
    catch(...){
        cerr << "Unknown Error!";
    }

    endl(cout);

    return(0);
}
