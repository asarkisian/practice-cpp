#include "poker.h"
#include <cctype>
#include <iostream>
using std::string;
using std::getline;
using std::ws;

void CPoker::getPlayersName()
{
	std::cout << "Enter your name: ";
    std::cin >> ws;
    getline(std::cin, playersName);

    playersName[0] = toupper(playersName[0]);    
}
