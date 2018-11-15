#include <iostream>

using namespace std;


int main(int argc, char** argv){
    
    string sentence = "";
    char replace = ' ';
    char replace_with = ' ';

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    cout << "Enter a character to replace: ";
    cin >> replace;

    cout << "Enter a character to replace with:";
    cin >> replace_with;

    for(int i=0; i<sentence.length(); i++){

        if(sentence[i] == replace){
            sentence[i] = replace_with;
        }
    }

    cout << "Modified sentence: " << sentence << endl;

    return(0);
}
