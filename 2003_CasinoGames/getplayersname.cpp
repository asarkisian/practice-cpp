#include "game.h"
using std::cout;
using std::cin;
using std::string;
using std::ws;
using std::getline;

string getPlayersName()
{
    string pName;

    cout << "Enter your name: __________\b\b\b\b\b\b\b\b\b\b";
    cin >> ws;
    getline(cin, pName);
    pName[0] = toupper(pName[0]);
    
    return pName;
}
