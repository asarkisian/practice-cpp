#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string tmp) {

    string tmp_back = "";
    bool is_match = false;

    for(int i = tmp.length() - 1; i >= 0; i--) {
        tmp_back += tmp.at(i);
    }

    if(tmp.compare(tmp_back) == 0){
        is_match = true;
    }

    return is_match;
}

int main()
{
    string temp;
    int count = 0;

    while(true) {

        if(count > 10)
            break;

        cout << "Enter a palindrome: ";
        getline(cin, temp);

        if(is_palindrome(temp)){
            cout << "Palindrome Detected!";
        }
        else{
            cout << "Palindrome Not Detected!";
        }

        endl(cout);

        count += 1;
    }

    return 0;
}
