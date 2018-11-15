#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;


void bubble_sort(vector<string>& l){

    string tmp = "";

    for(int x=0; x<l.size(); x++){
        for(int y=0; y<l.size()-1; y++){
            if(l.at(x) < l.at(y)){
                tmp = l.at(x);
                l.at(x) = l.at(y);
                l.at(y) = tmp;
            }
        }
    }
}


int main(int argc, char** argv){

    vector<string> list;
    list.push_back("1");
    list.push_back("2");
    list.push_back("3");
    list.push_back("5");
    list.push_back("9");
    list.push_back("4");
    list.push_back("6");
    list.push_back("8");
    list.push_back("7");

    bubble_sort(list);

    for(unsigned int i=0; i<list.size(); i++){
        cout << list.at(i) << endl;
    }

    return(0);
}
