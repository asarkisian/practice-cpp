#include "poker.h"


void CPoker::checkFlush()
{
//detecting flush
    if(spadeCounter == 5 || heartCounter == 5 || clubCounter == 5
    || diamondCounter == 5)
    {
        isComputerRoyalFlush = false;
	isComputerStraightFlush = false;
	isComputerFourOfAKind = false;
	isComputerFullHouse = false;
	isComputerFlush = true;
	isComputerStraight = false;
	isComputerThreeOfAKind = false;
	isComputerTwoPair = false;
	isComputerOnePair = false;
	isComputerNoHand = false;
    }

    if(isHumanRoyalFlush == false && isHumanStraightFlush == false
    && isHumanFourOfAKind == false && isHumanFullHouse == false)
    {
	if(spadeHumanCounter == 5 || heartHumanCounter == 5 || clubHumanCounter == 5
	|| diamondHumanCounter == 5)
	{
		isHumanRoyalFlush = false;
		isHumanStraightFlush = false;
		isHumanFourOfAKind = false;
		isHumanFullHouse = false;
		isHumanFlush = true;
		isHumanStraight = false;
		isHumanThreeOfAKind = false;
		isHumanTwoPair = false;
		isHumanOnePair = false;
		isHumanNoHand = false;
	}
    }
}
