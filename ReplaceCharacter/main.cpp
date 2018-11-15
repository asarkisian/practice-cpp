#include <iostream>
#include <string>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::getline;
using std::string;


void replace_character(string& str, char f, char r){

    for(unsigned int i=0; i<str.length(); i++){

        if(toupper(str[i]) == toupper(f)){
            str[i] = r; 
        }
    }

    return;
}


int main(int argc, char** argv){

    char find_char = '\0';
    char rep_char = '\0';
    string content = "";

    cout << "Enter a string: ";
    getline(cin, content);

    cout << "Find a character to replace: ";
    cin >> find_char;

    cout << "Replace \'" << find_char << "\' with which character? ";
    cin >> rep_char;
    
    replace_character(content, find_char, rep_char);

    cout << "Replaced string: " << content << endl;

    return(0);
}
