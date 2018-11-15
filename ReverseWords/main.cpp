#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;


string reverse_word(string w){

    // store the reversed word in a temp location
    string temp_word = "";
 
    // reverse the word
    for(int i=w.length()-1; i>-1; i--){

        // store the letter
        temp_word += w[i];
    }

    return(temp_word);
}


int main(int argc, char** argv){

    string word = "";

    cout << "Enter a word: ";
    getline(cin, word);

    word = reverse_word(word);
    cout << "Reversed: " << word << endl;

    return(0);
}
