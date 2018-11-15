#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::getline;
using std::rand;
using std::srand;
using std::string;
using std::time;
using std::vector;


string scramble_words(const string c){

    srand(time(NULL));

    int rand_int = 0;
    vector<string> words;
    string temp_word = "";
    string scrambled_word = "";

    // gather up all the words
    for(int i=0; i<c.length(); ++i){

        if(c[i] == ' '){
            words.push_back(temp_word);
            temp_word = "";
        }
        else{
            temp_word += c[i];
            if(i >= c.length()-1){
                words.push_back(temp_word);
            }
        }
    }

    // scramble the words
    for(int i=words.size()-1; i>=0; --i){
        rand_int = rand() % words.size();
        scrambled_word += words.at(rand_int) + ' ';
        words.erase(words.begin() + rand_int);
    }

    return(scrambled_word);
}

void do_main(){

    string content = "";
    string updated_content = "";

    cout << "Enter a sentence to scramble: ";
    getline(cin, content);

    updated_content = scramble_words(content);
    cout << "Scrambled Sentence: " << updated_content << endl;
}


int main(int argc, char** argv){

    try{
        do_main();
    }
    catch(const exception& e){
        cerr << e.what();
    }
    catch(...){
        cerr << "Unknown Internal Error!";
    }

    endl(cout);

    return(0);
}
