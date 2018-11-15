#include "blackjack.h"
#include "poker.h"
using std::string;

/*
------- BLACK JACK -------

* DEAL CARDS               -$5
* PLAYER WIN               +$10
* PLAYER BLACKJACK         +$20


--------- POKER ---------
* DEAL CARDS               -$5
* STRAIGHT WIN             +$10
* FLUSH WIN                +$10
* FULL HOUSE WIN           +$15
* FOUR OF A KIND WIN       +$20
* STRAIGHT FLUSH WIN       +$15
* ROYAL FLUSH WIN          +$25
*/

const int PLAYERWIN        = 10;
const int BLACKJACKWIN     = 20;
const int STRAIGHTWIN      = 10;
const int FLUSHWIN         = 10;
const int FULLHOUSEWIN     = 15;
const int FOUROFAKINDWIN   = 15;
const int STRAIGHTFLUSHWIN = 20;
const int ROYALFLUSHWIN    = 25;

void CBlackjack::calcPlayerMoney(string status)
{
    if(status == "DEAL")
    {
        playerMoney -= wagerAmount;
    }
    else if(status == "BLACKJACK WIN")
    {
        playerMoney += (wagerAmount + wagerAmount + BLACKJACKWIN);
    }
    else if(status == "PLAYER WIN")
    {
        playerMoney += (wagerAmount + wagerAmount);
    }
    else if(status == "DRAW GAME")
    {
        playerMoney += wagerAmount;
    }
}

void CPoker::calcPlayerMoney(string status)
{
    if(status == "DEAL")
    {
        playerMoney -= wagerAmount;
    }
    else if(status == "ROYAL FLUSH")
    {
        playerMoney += (wagerAmount + wagerAmount + ROYALFLUSHWIN);
    }
    else if(status == "STRAIGHT FLUSH")
    {
        playerMoney += (wagerAmount + wagerAmount + STRAIGHTFLUSHWIN);
    }
    else if(status == "FOFAK")
    {
        playerMoney += (wagerAmount + wagerAmount + FOUROFAKINDWIN);
    }
    else if(status == "FULL HOUSE")
    {
        playerMoney += (wagerAmount + wagerAmount + FULLHOUSEWIN);
    }
    else if(status == "FLUSH")
    {
        playerMoney += (wagerAmount + wagerAmount + FLUSHWIN);
    }
    else if(status == "STRAIGHT")
    {
        playerMoney += (wagerAmount + wagerAmount + STRAIGHTWIN);
    }
    else if(status == "OTHER")
    {
        playerMoney += (wagerAmount + wagerAmount);
    }
    else if(status == "DRAW GAME")
    {
        playerMoney += wagerAmount;
    }
}
