#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

typedef string name_t;

vector<char> splitString(const name_t n){

    vector<char> tmp;
    
    for(int i=0; i<n.length(); i++){
        tmp.push_back(n.at(i));
    }

    return tmp;
}

string joinString(const vector<char> ol){

    string ordered = "";

    for(int i=0; i<ol.size(); i++){
        ordered += ol.at(i);
    }

    return ordered;
}

vector<char> sortArray(vector<char> ul){

    char temp = '\0';

    for(int x=0; x<ul.size(); x++){
        for(int y=0; y<ul.size(); y++){
            if(ul.at(x) < ul.at(y)){
                temp = ul.at(x);
                ul.at(x) = ul.at(y);
                ul.at(y) = temp;
            }
        }
    }

    return ul;
}

int main(){

    // full name
    name_t name = "armond sarkisian";
    name_t sorted_name = "";

    // split string
    vector<char> unordered_list = splitString(name);
    vector<char> ordered_list = sortArray(unordered_list);
    sorted_name = joinString(ordered_list);

    cout << "Standard Name: " << name << endl;
    cout << "Sorted Name: " << sorted_name << endl;

    return 0;
}
