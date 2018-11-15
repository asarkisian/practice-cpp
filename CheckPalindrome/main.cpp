#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::toupper;

string reverse_word(string word){

    string temp = "";

    for(int i=word.length()-1; i>-1; i--){
        temp += word[i];
    }

    return(temp);
}

string convert_upper(string word){

    string temp = "";

    for(int i=0; i < word.length(); i++){
        temp += toupper(word[i]);
    }

    return(temp);
}


int main(int argc, char** argv){

    string word = "";

    do {
        cout << "Enter a palindrome or \'X\' to quit: ";
        getline(cin, word);
        if(word == "X"){
            break;
        }
        word = convert_upper(word);
        if( word == reverse_word(word)){
            cout << "Palindrome detected!" << endl;
        }

    } while(word != "X");

    return(0);
}
