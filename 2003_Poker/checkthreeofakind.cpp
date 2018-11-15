#include "poker.h"

void CPoker::checkThreeOfAKind()
{
//detecting three of a kind

    if(twoCounter == 3 || threeCounter == 3 || fourCounter == 3
    || fiveCounter == 3 || sixCounter == 3 || sevenCounter == 3
    || eightCounter == 3 || nineCounter == 3 || tenCounter == 3
    || jackCounter == 3 || queenCounter == 3 || kingCounter == 3
    || aceCounter == 3)
    {
        if(twoCounter == 3)
	{
	    computerWinDepth = 2;
	}
	else if(threeCounter == 3)
	{
	    computerWinDepth = 3;
	}
	else if(fourCounter == 3)
	{
	    computerWinDepth = 4;
	}
	else if(fiveCounter == 3)
	{
	    computerWinDepth = 5;
	}
	else if(sixCounter == 3)
	{
	    computerWinDepth = 6;
	}
	else if(sevenCounter == 3)
	{
	    computerWinDepth = 7;
	}
	else if(eightCounter == 3)
	{
	    computerWinDepth = 8;
	}
	else if(nineCounter == 3)
	{
	    computerWinDepth = 9;
	}
	else if(tenCounter == 3)
	{
	    computerWinDepth = 10;
	}
	else if(jackCounter == 3)
	{
	    computerWinDepth = 11;
	}
	else if(queenCounter == 3)
	{
	    computerWinDepth = 12;
	}
	else if(kingCounter == 3)
	{
	    computerWinDepth = 13;
	}
	else if(aceCounter == 3)
	{
	    computerWinDepth = 14;
	}

	isComputerRoyalFlush = false;
	isComputerStraightFlush = false;
	isComputerFourOfAKind = false;
	isComputerFullHouse = false;
	isComputerFlush = false;
	isComputerStraight = false;
	isComputerThreeOfAKind = true;
	isComputerTwoPair = false;
	isComputerOnePair = false;
	isComputerNoHand = false;
    }

    if(isHumanRoyalFlush == false && isHumanStraightFlush == false
    && isHumanFourOfAKind == false && isHumanFullHouse == false
    && isHumanFlush == false && isHumanStraight == false)
    {
	if(twoHumanCounter == 3 || threeHumanCounter == 3 || fourHumanCounter == 3
	|| fiveHumanCounter == 3 || sixHumanCounter == 3 || sevenHumanCounter == 3
	|| eightHumanCounter == 3 || nineHumanCounter == 3 || tenHumanCounter == 3
	|| jackHumanCounter == 3 || queenHumanCounter == 3 || kingHumanCounter == 3
	|| aceHumanCounter == 3)
	{

	if(twoHumanCounter == 3)
	{
	humanWinDepth = 2;
	}
	else if(threeHumanCounter == 3)
	{
	humanWinDepth = 3;
	}
	else if(fourHumanCounter == 3)
	{
	humanWinDepth = 4;
	}
	else if(fiveHumanCounter == 3)
	{
	humanWinDepth = 5;
	}
	else if(sixHumanCounter == 3)
	{
	humanWinDepth = 6;
	}
	else if(sevenHumanCounter == 3)
	{
	humanWinDepth = 7;
	}
	else if(eightHumanCounter == 3)
	{
	humanWinDepth = 8;
	}
	else if(nineHumanCounter == 3)
	{
	humanWinDepth = 9;
	}
	else if(tenHumanCounter == 3)
	{
	humanWinDepth = 10;
	}
	else if(jackHumanCounter == 3)
	{
	humanWinDepth = 11;
	}
	else if(queenHumanCounter == 3)
	{
	humanWinDepth = 12;
	}
	else if(kingHumanCounter == 3)
	{
	humanWinDepth = 13;
	}
	else if(aceHumanCounter == 3)
	{
	humanWinDepth = 14;
	}

	    isHumanRoyalFlush = false;
	    isHumanStraightFlush = false;
	    isHumanFourOfAKind = false;
	    isHumanFullHouse = false;
	    isHumanFlush = false;
	    isHumanStraight = false;
	    isHumanThreeOfAKind = true;
	    isHumanTwoPair = false;
	    isHumanOnePair = false;
	    isHumanNoHand = false;
	}
    }
}
