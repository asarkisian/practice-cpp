#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;


bool compare_lists(vector<string> l1, vector<string> l2){

    bool is_overall_match = true;
    bool is_element_match = false;
    vector<bool> all_matches;

    for(unsigned int x=0; x<l1.size(); x++){
        is_element_match = false;

        for(unsigned int y=0; y<l2.size(); y++){
            if(l1.at(x) == l2.at(y)){
                is_element_match = true;
            }
        }

        all_matches.push_back(is_element_match);
    }

    for(unsigned int i=0; i<all_matches.size(); i++){
        if(all_matches.at(i) == false){
            is_overall_match = false;
        }
    }

    return(is_overall_match);
}


int main(int argc, char** argv){

    vector<string> list_1;

    list_1.push_back("1");
    list_1.push_back("2");
    list_1.push_back("3");
    list_1.push_back("4");
    list_1.push_back("5");

    vector<string> list_2;

    list_2.push_back("2");
    list_2.push_back("4");
    list_2.push_back("5");
    list_2.push_back("1");
    list_2.push_back("6");

    cout << "Result: " << compare_lists(list_1, list_2);

    return(0);
}
