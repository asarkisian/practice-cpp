#include "poker.h"
using std::string;

/*
* DEAL CARDS               -$5

* NO HAND WIN              +$10
* PAIR WIN                 +$10
* TWO PAIR WIN             +$15
* THREE OF A KIND WIN      +$20
* STRAIGHT WIN             +$25
* FLUSH WIN                +$30
* FULL HOUSE WIN           +$50
* FOUR OF A KIND WIN       +$100
* STRAIGHT FLUSH WIN       +$150
* ROYAL FLUSH WIN          +$500
*/

const int LOWHANDWIN       = 5;
const int TWOPAIRWIN       = 5;
const int THREEOFAKINDWIN  = 5;
const int STRAIGHTWIN      = 10;
const int FLUSHWIN         = 10;
const int FULLHOUSEWIN     = 15;
const int FOUROFAKINDWIN   = 15;
const int STRAIGHTFLUSHWIN = 20;
const int ROYALFLUSHWIN    = 25;

void CPoker::calcPlayerMoney(string status)
{
    if(status == "DEAL")
    {
        playerMoney -= wagerAmount;
    }
    else if(status == "ROYAL FLUSH")
    {
        if(wagerAmount == 5)
	{
	    playerMoney += ROYALFLUSHWIN;
	}
	else
	{
	    playerMoney += (wagerAmount * ROYALFLUSHWIN);
	}
    }
    else if(status == "STRAIGHT FLUSH")
    {
        if(wagerAmount == 5)
	{
	    playerMoney += STRAIGHTFLUSHWIN;
	}
	else
	{
	    playerMoney += (wagerAmount * STRAIGHTFLUSHWIN);
	}
    }
    else if(status == "FOFAK")
    {
        if(wagerAmount == 5)
	{
	    playerMoney += FOUROFAKINDWIN;
	}
	else
	{
	    playerMoney += (wagerAmount * FOUROFAKINDWIN);
	}
    }
    else if(status == "FULL HOUSE")
    {
        if(wagerAmount == 5)
	{
	    playerMoney += FULLHOUSEWIN;
	}
	else
	{
	    playerMoney += (wagerAmount * FULLHOUSEWIN);
	}
    }
    else if(status == "FLUSH")
    {
        if(wagerAmount == 5)
	{
	    playerMoney += FLUSHWIN;
	}
	else
	{
	    playerMoney += (wagerAmount * FLUSHWIN);
	}
    }
    else if(status == "STRAIGHT")
    {
        if(wagerAmount == 5)
	{
	    playerMoney += STRAIGHTWIN;
	}
	else
	{
	    playerMoney += (wagerAmount * STRAIGHTWIN);
	}
    }
    else if(status == "OTHER")
    {
        if(wagerAmount == LOWHANDWIN)
	{
	    playerMoney += 10;
	}
	else
	{
	    playerMoney += (wagerAmount * LOWHANDWIN);
	}
    }
}
