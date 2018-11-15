#include <conio.h>
#include "game.h"
#include "blackjack.h"
#include "poker.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;

string getPlayersName();

void displayMenu()
{
    system("cls");
    selection_t myChoice = ' ';
    name_t      tempName = getPlayersName();
    money_t     tempMoney = 50;

    do
    {
        system("cls");
        cout << "\n\n";
        cout << "\t\t\t   -  Armond's Casino Games  -" << endl;
        cout << "\t\t\t   ===========================" << endl;
        cout << "\n\n";
        cout << "\t\t" << "*-----------------------------------------------*" << endl;
        cout << "\t\t" << "|                                               |" << endl;
        cout << "\t\t" << "|  (A) Play Vegas Style Blackjack               |" << endl;
        cout << "\t\t" << "|                                               |" << endl;
        cout << "\t\t" << "|  (B) Play Vegas Style Poker                   |" << endl;
        cout << "\t\t" << "|                                               |" << endl;
        cout << "\t\t" << "|  (X) Cash Out and Exit Casino                 |" << endl;
        cout << "\t\t" << "|                                               |" << endl;
        cout << "\t\t" << "*-----------------------------------------------*" << "\n\n";
        cout << "\t\t\t     " << tempName << "\'s Money: $" << tempMoney << ".00" << "\n\n";

        cout << "\nMake a selection: _\b";
        cin >> myChoice;
        myChoice = toupper(myChoice);

        switch(myChoice)
        {
        case 'A':
        {
            CGame* bj = new CBlackjack(tempName, tempMoney);
            while(bj->isPlayAgain == true)
            {
                tempMoney = bj->doMain();
            }
            delete bj;

            break;
        }
        case 'B':
        {
            CGame* pk = new CPoker(tempName, tempMoney);
            while(pk->isPlayAgain == true)
            {
                tempMoney = pk->doMain();
            }
            delete pk;

            break;
        }
        case 'X':
        {
            cout << "\t\t\t     Thank you for playing. Come back soon!" << "\n\n";
        }
        }

    }while(myChoice != 'X');
}
