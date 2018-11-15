#include "poker.h"

void CPoker::checkStraight()
{
//detecting straight pattern

    if(computerValueCount == 62 || computerValueCount == 124
    || computerValueCount == 248 || computerValueCount == 496
    || computerValueCount == 992 || computerValueCount == 1984
    || computerValueCount == 3968 || computerValueCount == 7972
    || computerValueCount == 15872)
    {
        isComputerRoyalFlush = false;
	isComputerStraightFlush = false;
	isComputerFourOfAKind = false;
	isComputerFullHouse = false;
	isComputerFlush = false;
	isComputerStraight = true;
	isComputerThreeOfAKind = false;
	isComputerTwoPair = false;
	isComputerOnePair = false;
	isComputerNoHand = false;
    }

    if(isHumanRoyalFlush == false && isHumanStraightFlush == false
    && isHumanFourOfAKind == false && isHumanFullHouse == false
    && isHumanFlush == false)
    {
	if(humanValueCount == 62 || humanValueCount == 124
	|| humanValueCount == 248 || humanValueCount == 496
	|| humanValueCount == 992 || humanValueCount == 1984
	|| humanValueCount == 3968 || humanValueCount == 7972
	|| humanValueCount == 15872)
	{
		isHumanRoyalFlush = false;
		isHumanStraightFlush = false;
		isHumanFourOfAKind = false;
		isHumanFullHouse = false;
		isHumanFlush = false;
		isHumanStraight = true;
		isHumanThreeOfAKind = false;
		isHumanTwoPair = false;
		isHumanOnePair = false;
		isHumanNoHand = false;
        }
    }
}