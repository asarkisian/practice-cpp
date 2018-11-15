#include "poker.h"

void CPoker::checkStraightFlush()
{
//detecting straight flush pattern

    if((computerValueCount == 62 || computerValueCount == 124
    || computerValueCount == 248 || computerValueCount == 496
    || computerValueCount == 992 || computerValueCount == 1984
    || computerValueCount == 3968 || computerValueCount == 7972)
    && (heartCounter == 5 || spadeCounter == 5 || clubCounter == 5
    || diamondCounter == 5))
    {
        isComputerRoyalFlush = false;
	isComputerStraightFlush = true;
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
	if((humanValueCount == 62 || humanValueCount == 124
	|| humanValueCount == 248 || humanValueCount == 496
	|| humanValueCount == 992 || humanValueCount == 1984
	|| humanValueCount == 3968 || humanValueCount == 7972)
	&& (heartHumanCounter == 5 || spadeHumanCounter == 5 || clubHumanCounter == 5
	|| diamondHumanCounter == 5))
	{
		isHumanRoyalFlush = false;
		isHumanStraightFlush = true;
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
