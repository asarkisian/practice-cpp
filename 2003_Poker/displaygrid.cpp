#include "poker.h"
#include <iostream>
using std::cout;
using std::endl;

void CPoker::displayGrid()const
{
    cout << "\t\t" << "*-----------------------------------------------*" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|                    -DEALER-                   |" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|-----------------------------------------------|" << endl;
    cout << "\t\t" << "|   " << computerHand[0] << "  |   " << computerHand[1] << "   |   " << computerHand[2] << "   |   " << computerHand[3] << "  |   " << computerHand[4] << "   |" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|   " << playerHand[0] << "  |   " << playerHand[1] << "   |   " << playerHand[2] << "   |   " << playerHand[3] << "  |   " << playerHand[4] << "   |" << endl;
    cout << "\t\t" << "|-----------------------------------------------|" << endl;
    cout << "\t\t" << "|   (1)      (2)       (3)       (4)      (5)   |" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|   (6) WHEN DONE:   -PLAYER-                   |" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "*-----------------------------------------------*" << "\n\n";
    cout << playersName << "\'s Money: $" << playerMoney << ".00" << "\n\n";
}
