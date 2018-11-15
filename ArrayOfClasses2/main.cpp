#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "my_class.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::getline;
using std::vector;


int main(int argc, char** argv){

    try{
        vector<MyClass*>* mcs = new vector<MyClass*>;

        mcs->push_back(new MyClass(string("Henry")));
        mcs->push_back(new MyClass(string("Albert")));
        mcs->push_back(new MyClass(string("Hillary")));
        mcs->push_back(new MyClass(string("Bob")));
 
        // change only the first name
        mcs->at(0)->change_name("Jeffrey");

        // display all the names
        for(unsigned int i=0; i<mcs->size(); i++){
            cout << "Name: " << mcs->at(i)->get_name() << endl;
        }

        // delete each individual element
        for(unsigned int i=0; i<mcs->size(); i++){
            delete mcs->at(i);
        }

        // delete the container
        delete mcs;
    }
    catch(const exception& e){
        cerr << "Error: " << e.what() << '!' << endl;
    }
    catch(...){
        cerr << "Error: Unknown internal exception!" << endl;
    }

    // exit
    return(EXIT_SUCCESS);
}
