#include "poker.h"

void CPoker::checkFourOfAKind()
{
//detecting four of a kind pattern

    if(twoCounter == 4 || threeCounter == 4 || fourCounter == 4
    || fiveCounter == 4 || sixCounter == 4 || sevenCounter == 4
    || eightCounter == 4 || nineCounter == 4 || tenCounter == 4
    || jackCounter == 4 || queenCounter == 4 || kingCounter == 4
    || aceCounter == 4)
    {
    if(twoCounter == 4)
	{
	    computerWinDepth = 2;
	}
	else if(threeCounter == 4)
	{
	    computerWinDepth = 3;
	}
	else if(fourCounter == 4)
	{
	    computerWinDepth = 4;
	}
	else if(fiveCounter == 4)
	{
	    computerWinDepth = 5;
	}
	else if(sixCounter == 4)
	{
	    computerWinDepth = 6;
	}
	else if(sevenCounter == 4)
	{
	    computerWinDepth = 7;
	}
	else if(eightCounter == 4)
	{
	    computerWinDepth = 8;
	}
	else if(nineCounter == 4)
	{
	    computerWinDepth = 9;
	}
	else if(tenCounter == 4)
	{
	    computerWinDepth = 10;
	}
	else if(jackCounter == 4)
	{
	    computerWinDepth = 11;
	}
	else if(queenCounter == 4)
	{
	    computerWinDepth = 12;
	}
	else if(kingCounter == 4)
	{
	    computerWinDepth = 13;
	}
	else if(aceCounter == 4)
	{
	    computerWinDepth = 14;
	}
        isComputerRoyalFlush = false;
	isComputerStraightFlush = false;
	isComputerFourOfAKind = true;
	isComputerFullHouse = false;
	isComputerFlush = false;
	isComputerStraight = false;
	isComputerThreeOfAKind = false;
	isComputerTwoPair = false;
	isComputerOnePair = false;
	isComputerNoHand = false;
    }

    if(isHumanRoyalFlush == false && isHumanStraightFlush == false)
    {
	if(twoHumanCounter == 4 || threeHumanCounter == 4 || fourHumanCounter == 4
	|| fiveHumanCounter == 4 || sixHumanCounter == 4 || sevenHumanCounter == 4
	|| eightHumanCounter == 4 || nineHumanCounter == 4 || tenHumanCounter == 4
	|| jackHumanCounter == 4 || queenHumanCounter == 4 || kingHumanCounter == 4
	|| aceHumanCounter == 4)
	{

	if(twoHumanCounter == 4)
	{
	    humanWinDepth = 2;
	}
	else if(threeHumanCounter == 4)
	{
	    humanWinDepth = 3;
	}
	else if(fourHumanCounter == 4)
	{
	    humanWinDepth = 4;
	}
	else if(fiveHumanCounter == 4)
	{
	    humanWinDepth = 5;
	}
	else if(sixHumanCounter == 4)
	{
	    humanWinDepth = 6;
	}
	else if(sevenHumanCounter == 4)
	{
	    humanWinDepth = 7;
	}
	else if(eightHumanCounter == 4)
	{
	    humanWinDepth = 8;
	}
	else if(nineHumanCounter == 4)
	{
	    humanWinDepth = 9;
	}
	else if(tenHumanCounter == 4)
	{
	    humanWinDepth = 10;
	}
	else if(jackHumanCounter == 4)
	{
	    humanWinDepth = 11;
	}
	else if(queenHumanCounter == 4)
	{
	    humanWinDepth = 12;
	}
	else if(kingHumanCounter == 4)
	{
	    humanWinDepth = 13;
	}
	else if(aceHumanCounter == 4)
	{
	    humanWinDepth = 14;
	}
		isHumanRoyalFlush = false;
		isHumanStraightFlush = false;
		isHumanFourOfAKind = true;
		isHumanFullHouse = false;
		isHumanFlush = false;
		isHumanStraight = false;
		isHumanThreeOfAKind = false;
		isHumanTwoPair = false;
		isHumanOnePair = false;
		isHumanNoHand = false;
	}
    }
}
