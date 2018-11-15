#include <iostream>
#include <string>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::getline;
using std::string;


string delete_character(const string txt, const char d){

    string temp = "";

    for(unsigned int i=0; i<txt.length(); i++){
        if(toupper(txt[i]) != toupper(d)){
            temp.push_back(txt[i]);
        }
    }

    return temp;
}

int main(int argc, char** argv){

    char d_char = '\0';
    string text = "";
    string updated_text = "";

    cout << "Enter some text: ";
    getline(cin, text);

    cout << "Enter a character to delete: ";
    cin >> d_char;

    updated_text = delete_character(text, d_char);

    cout << "Old text: " << text << endl;
    cout << "New text: " << updated_text << endl;

    return(0);
}
