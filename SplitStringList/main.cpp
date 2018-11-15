#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;


vector<string> split_string(const string str){

    string mod_str = "";
    string temp = "";
    vector<string> tmp_list;

    for(unsigned int i=0; i<str.length(); i++){

        if(str[i] != ' '){
            temp += str[i];
        }
        else{
            tmp_list.push_back(temp);
            temp = "";
        }

        if(i == str.length()-1){
            tmp_list.push_back(temp);
            temp = "";
        }

    }

    return tmp_list;
}

int main(int argc, char** argv){
    
    int list_size = 0;
    string text = "have a wonderful day";
    vector<string> list;

    list = split_string(text);

    list_size = (int)list.size();

    for(int i=list_size - 1; i>=0; --i){

        cout << list.at(i) << ' ';
    }

    return(0);
}
