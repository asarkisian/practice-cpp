#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string name_t;

void displayNames(const vector<name_t> n){

    for(int i=0; i<n.size(); i++){
         cout << "Name: " << n.at(i) << endl;
    }

    return;
}


void deleteStartsWith(const string sw, vector<name_t>& n){

    for(int i=n.size()-1; i>= 0; i--){

        // find the sub-string
        if(n.at(i).find(sw) != string::npos)
        {
            n.erase(n.begin() + i);
        }
    }

    return;
}


int main(){

    vector<name_t> names;

    while(true){
        names.clear();
        string starts_with = "";

        names.push_back(name_t("albert"));
        names.push_back(name_t("jimmy"));
        names.push_back(name_t("brian"));
        names.push_back(name_t("brianna"));
        names.push_back(name_t("brio"));
        names.push_back(name_t("allen"));
        names.push_back(name_t("alex"));
        names.push_back(name_t("alexander"));
        names.push_back(name_t("jim"));
        names.push_back(name_t("bimmy"));
        names.push_back(name_t("billy"));
        names.push_back(name_t("jill"));
        names.push_back(name_t("jackson"));
        names.push_back(name_t("jack"));

        cout << "Enter a starts-with expression to delete: ";
        getline(cin, starts_with);

        deleteStartsWith(starts_with, names);
        displayNames(names);
    }

    return 0;
}
