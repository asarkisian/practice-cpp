#include "blackjack.h"
#include "poker.h"
using std::cout;
using std::endl;

void CBlackjack::displayGrid()const
{
    cout << "\t\t" << "*-----------------------------------------------*" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|                    -DEALER-                   |" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|-----------------------------------------------|" << endl;

    if(isHumanStay == true && isHumanHit == false)
    {
        cout << "\t\t" << "|" << computerHand[0] << "|" << computerHand[1] <<"|" << computerHand[2] <<"|" << computerHand[3] <<"|" << computerHand[4] << "|" << computerHand[5] << "|" << computerHand[6] << "|" << computerHand[7] << "|" << computerHand[8] << "|" << computerHand[9] << "|" << computerHand[10] << "|" << computerHand[11] << "|" << endl;
    }
    else
    {
        cout << "\t\t" << "|" << "   " <<"|" << computerHand[1] <<"|" << computerHand[2] <<"|" << computerHand[3] <<"|" << computerHand[4] << "|" << computerHand[5] << "|" << computerHand[6] << "|" << computerHand[7] << "|" << computerHand[8] << "|" << computerHand[9] << "|" << computerHand[10] << "|" << computerHand[11] << "|" << endl;
    }

    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|" << playerHand[0] <<"|" << playerHand[1] <<"|" << playerHand[2] <<"|" << playerHand[3] <<"|" << playerHand[4] << "|" << playerHand[5] << "|" << playerHand[6] << "|" << playerHand[7] << "|" << playerHand[8] << "|" << playerHand[9] << "|" << playerHand[10] << "|" << playerHand[11] << "|" << endl;
    cout << "\t\t" << "|-----------------------------------------------|" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "|                    -PLAYER-                   |" << endl;
    cout << "\t\t" << "|                                               |" << endl;
    cout << "\t\t" << "*-----------------------------------------------*" << "\n\n";
    cout << playersName << "\'s Money: $" << playerMoney << ".00" << "\n\n";
}

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
