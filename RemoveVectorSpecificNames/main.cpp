#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

typedef string name_t;

vector<name_t> removeVectorWithChar(const char remove, vector<name_t> n){

    for(int i=n.size()-1; i>=0; i--){
        if(n.at(i).at(0) == remove){
            n.erase(n.begin() + i);
        }
    }

    return n;
}

void displayVector(const char remove, const vector<name_t> n){

    cout << "\nNames:" << endl;

    for(int i=0; i<n.size(); i++){
        cout << n.at(i) << endl;
    }

    return;
}

int main(){

    char remove = '\0';
    vector<string> names;

    names.push_back(name_t("albert"));
    names.push_back(name_t("henry"));
    names.push_back(name_t("jim"));
    names.push_back(name_t("alexander"));
    names.push_back(name_t("will"));
    names.push_back(name_t("arthur"));
    names.push_back(name_t("bob"));
    names.push_back(name_t("bill"));
    
    cout << "Enter a character to remove: ";
    cin >> remove;

    remove = tolower(remove);
    
    displayVector(remove, removeVectorWithChar(remove, names));

    return 0;
}
