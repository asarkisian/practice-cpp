#include "poker.h"


void CPoker::checkFullHouse()
{
//detecting full house

    if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
     || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
     || eightCounter == 2 || nineCounter == 2 || jackCounter == 2
     || queenCounter == 2 || kingCounter == 2 || aceCounter == 2)
     && (twoCounter == 3 || threeCounter == 3 || fourCounter == 3
     ||  fiveCounter == 3 || sixCounter == 3 || sevenCounter == 3
     ||  eightCounter == 3 || nineCounter == 3 || jackCounter == 3
     ||  queenCounter == 3 || kingCounter == 3 || aceCounter == 3))
    {
        isComputerRoyalFlush = false;
	isComputerStraightFlush = false;
	isComputerFourOfAKind = false;
	isComputerFullHouse = true;
	isComputerFlush = false;
	isComputerStraight = false;
	isComputerThreeOfAKind = false;
	isComputerTwoPair = false;
	isComputerOnePair = false;
	isComputerNoHand = false;
    }

    if(isHumanRoyalFlush == false && isHumanStraightFlush == false
    && isHumanFourOfAKind == false)
    {
	if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
	|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
	|| eightHumanCounter == 2 || nineHumanCounter == 2 || jackHumanCounter == 2
	|| queenHumanCounter == 2 || kingHumanCounter == 2 || aceHumanCounter == 2)
	&& (twoHumanCounter == 3 || threeHumanCounter == 3 || fourHumanCounter == 3
	||  fiveHumanCounter == 3 || sixHumanCounter == 3 || sevenHumanCounter == 3
	||  eightHumanCounter == 3 || nineHumanCounter == 3 || jackHumanCounter == 3
	||  queenHumanCounter == 3 || kingHumanCounter == 3 || aceHumanCounter == 3))
	{
		isHumanRoyalFlush = false;
		isHumanStraightFlush = false;
		isHumanFourOfAKind = false;
		isHumanFullHouse = true;
		isHumanFlush = false;
		isHumanStraight = false;
		isHumanThreeOfAKind = false;
		isHumanTwoPair = false;
		isHumanOnePair = false;
		isHumanNoHand = false;
	}
    }
}
