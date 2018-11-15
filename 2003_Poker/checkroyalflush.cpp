#include "poker.h"

void CPoker::checkRoyalFlush()
{
//detecting royal flush pattern

    if(computerValueCount == 15872 && (heartCounter == 5
    || spadeCounter == 5 || clubCounter == 5 || diamondCounter == 5))
    {
        isComputerRoyalFlush = true;
	isComputerStraightFlush = false;
	isComputerFourOfAKind = false;
	isComputerFullHouse = false;
	isComputerFlush = false;
	isComputerStraight = false;
	isComputerThreeOfAKind = false;
	isComputerTwoPair = false;
	isComputerOnePair = false;
	isComputerNoHand = false;
    }

    if(isHumanRoyalFlush == false)
    {
	if(humanValueCount == 15872 && (heartHumanCounter == 5
	|| spadeHumanCounter == 5 || clubHumanCounter == 5 || diamondHumanCounter == 5))
	{
		isHumanRoyalFlush = true;
		isHumanStraightFlush = false;
		isHumanFourOfAKind = false;
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
