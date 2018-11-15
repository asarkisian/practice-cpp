#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::getline;
using std::rand;
using std::srand;
using std::string;
using std::time;
using std::vector;


vector<string> create_deck(){
        vector<string> temp;
        
        temp.push_back("AH");
        temp.push_back("2H");
        temp.push_back("3H");
        temp.push_back("4H");
        temp.push_back("5H");
        temp.push_back("6H");
        temp.push_back("7H");
        temp.push_back("8H");
        temp.push_back("9H");
        temp.push_back("1H");
        temp.push_back("JH");
        temp.push_back("QH");
        temp.push_back("KH");

        temp.push_back("AC");
        temp.push_back("2C");
        temp.push_back("3C");
        temp.push_back("4C");
        temp.push_back("5C");
        temp.push_back("6C");
        temp.push_back("7C");
        temp.push_back("8C");
        temp.push_back("9C");
        temp.push_back("1C");
        temp.push_back("JC");
        temp.push_back("QC");
        temp.push_back("KC");

        temp.push_back("AS");
        temp.push_back("2S");
        temp.push_back("3S");
        temp.push_back("4S");
        temp.push_back("5S");
        temp.push_back("6S");
        temp.push_back("7S");
        temp.push_back("8S");
        temp.push_back("9S");
        temp.push_back("1S");
        temp.push_back("JS");
        temp.push_back("QS");
        temp.push_back("KS");

        temp.push_back("AD");
        temp.push_back("2D");
        temp.push_back("3D");
        temp.push_back("4D");
        temp.push_back("5D");
        temp.push_back("6D");
        temp.push_back("7D");
        temp.push_back("8D");
        temp.push_back("9D");
        temp.push_back("1D");
        temp.push_back("JD");
        temp.push_back("QD");
        temp.push_back("KD");

        return(temp);
}


void display_deck(const vector<string> d){

    for(int i=0; i<d.size(); i++){
        cout << d.at(i) << endl;
    }

    cout << "Size of deck: " << d.size() << endl;
}


bool contains(const int val, const vector<int> l){

    bool is_contains = false;

    for(int i=0; i<l.size(); i++){
        if(l.at(i) == val){
            is_contains = true;
            break;
        }
    }

    return(is_contains);
}



vector<string> randomize_deck(const vector<string> d){
    srand(time(NULL));

    vector<string> temp;
    vector<int> used_elements;
    int rand_num = 0;
    bool is_use_element = true;

    for(int i=0; i<d.size(); i++){

        while(true){
  
            // generate a random number
            rand_num = rand() % d.size();

            if(!contains(rand_num, used_elements)){
                temp.push_back(d.at(rand_num)); 
                used_elements.push_back(rand_num);
                break;
            }
        }
    }

    return(temp);
}


int main(int argc, char** argv){

    try{

        vector<string> deck_of_cards;

        deck_of_cards = create_deck();

        deck_of_cards = randomize_deck(deck_of_cards);
        
        display_deck(deck_of_cards);
    }
    catch(const exception& e){
        cerr << "Error: " << e.what() << endl;
    }
    catch(...){
        cerr << "Error: Unknown exception!" << endl;
    }

    return(0);
}
