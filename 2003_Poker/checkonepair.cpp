#include "poker.h"

void CPoker::checkOnePair()
{
//detecting one pair

    if(twoCounter == 2 || threeCounter == 2 || fourCounter == 2
    || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
    || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
    || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
    || aceCounter == 2)
    {
        if(twoCounter == 2)
	{
	    computerWinDepth = 2;
	}
	else if(threeCounter == 2)
	{
	    computerWinDepth = 3;
	}
	else if(fourCounter == 2)
	{
	    computerWinDepth = 4;
	}
	else if(fiveCounter == 2)
	{
	    computerWinDepth = 5;
	}
	else if(sixCounter == 2)
	{
	    computerWinDepth = 6;
	}
	else if(sevenCounter == 2)
	{
	    computerWinDepth = 7;
	}
	else if(eightCounter == 2)
	{
	    computerWinDepth = 8;
	}
	else if(nineCounter == 2)
	{
	    computerWinDepth = 9;
	}
	else if(tenCounter == 2)
	{
	    computerWinDepth = 10;
	}
	else if(jackCounter == 2)
	{
	    computerWinDepth = 11;
	}
	else if(queenCounter == 2)
	{
	    computerWinDepth = 12;
	}
	else if(kingCounter == 2)
	{
	    computerWinDepth = 13;
	}
	else if(aceCounter == 2)
	{
	    computerWinDepth = 14;
	}

	isComputerRoyalFlush = false;
	isComputerStraightFlush = false;
	isComputerFourOfAKind = false;
	isComputerFullHouse = false;
	isComputerFlush = false;
	isComputerStraight = false;
	isComputerThreeOfAKind = false;
	isComputerTwoPair = false;
	isComputerOnePair = true;
	isComputerNoHand = false;
    }

    if(isHumanRoyalFlush == false && isHumanStraightFlush == false
    && isHumanFourOfAKind == false && isHumanFullHouse == false
    && isHumanFlush == false && isHumanStraight == false
    && isHumanThreeOfAKind == false && isHumanTwoPair == false)
    {
	if(twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
	|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
	|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
	|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
	|| aceHumanCounter == 2)
	{

	if(twoHumanCounter == 2)
	{
	    humanWinDepth = 2;
	}
	else if(threeHumanCounter == 2)
	{
	    humanWinDepth = 3;
	}
	else if(fourHumanCounter == 2)
	{
	    humanWinDepth = 4;
	}
	else if(fiveHumanCounter == 2)
	{
	    humanWinDepth = 5;
	}
	else if(sixHumanCounter == 2)
	{
	    humanWinDepth = 6;
	}
	else if(sevenHumanCounter == 2)
	{
	    humanWinDepth = 7;
	}
	else if(eightHumanCounter == 2)
	{
	    humanWinDepth = 8;
	}
	else if(nineHumanCounter == 2)
	{
	    humanWinDepth = 9;
	}
	else if(tenHumanCounter == 2)
	{
	    humanWinDepth = 10;
	}
	else if(jackHumanCounter == 2)
	{
	    humanWinDepth = 11;
	}
	else if(queenHumanCounter == 2)
	{
	    humanWinDepth = 12;
	}
	else if(kingHumanCounter == 2)
	{
	    humanWinDepth = 13;
	}
	else if(aceHumanCounter == 2)
	{
	    humanWinDepth = 14;
	}

		isHumanRoyalFlush = false;
		isHumanStraightFlush = false;
		isHumanFourOfAKind = false;
		isHumanFullHouse = false;
		isHumanFlush = false;
		isHumanStraight = false;
		isHumanThreeOfAKind = false;
		isHumanTwoPair = false;
		isHumanOnePair = true;
		isHumanNoHand = false;
	}
    }
}