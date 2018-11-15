#include "poker.h"

void CPoker::checkTwoPair()
{
//detecting two pair

    if(twoCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (threeCounter == 2 || fourCounter == 2 || fiveCounter == 2
	 || sixCounter == 2 || sevenCounter == 2 || eightCounter == 2
	 || nineCounter == 2 || tenCounter == 2 || nineCounter == 2
	 || tenCounter == 2 || jackCounter == 2 || queenCounter == 2
	 || kingCounter == 2 || aceCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }
    else if(threeCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (twoCounter == 2 || fourCounter == 2 || fiveCounter == 2
	 || sixCounter == 2 || sevenCounter == 2 || eightCounter == 2
	 || nineCounter == 2 || tenCounter == 2 || jackCounter == 2
	 || queenCounter == 2 ||kingCounter == 2 || aceCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }
    else if(fourCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (twoCounter == 2 || threeCounter == 2 || fiveCounter == 2
	 || sixCounter == 2 || sevenCounter == 2 || eightCounter == 2
	 || nineCounter == 2 || tenCounter == 2 || jackCounter == 2
	 || queenCounter == 2 || kingCounter == 2 || aceCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }
    else if(fiveCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (twoCounter == 2 || threeCounter == 2 || fourCounter == 2
	 || sixCounter == 2 || sevenCounter == 2 || eightCounter == 2
	 || nineCounter == 2 || tenCounter == 2 || jackCounter == 2
	 || queenCounter == 2 || kingCounter == 2 || aceCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }
    else if(sixCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (twoCounter == 2 || threeCounter == 2 || fourCounter == 2
	 || fiveCounter == 2 || sevenCounter == 2 || eightCounter == 2
	 || nineCounter == 2 || tenCounter == 2 || jackCounter == 2
	 || queenCounter == 2 || kingCounter == 2 || aceCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }
    else if(sevenCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (twoCounter == 2 || threeCounter == 2 || fourCounter == 2
	 || fiveCounter == 2 || sixCounter == 2 || eightCounter == 2
	 || nineCounter == 2 || tenCounter == 2 || jackCounter == 2
	 || queenCounter == 2 || kingCounter == 2 || aceCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }
    else if(eightCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (twoCounter == 2 || threeCounter == 2 || fourCounter == 2
	 || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
	 || nineCounter == 2 || tenCounter == 2 || jackCounter == 2
	 || queenCounter == 2 || kingCounter == 2 || aceCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }
    else if(nineCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (twoCounter == 2 || threeCounter == 2 || fourCounter == 2
	 || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
	 || eightCounter == 2 || tenCounter == 2 || jackCounter == 2
	 || queenCounter == 2 || kingCounter == 2 || aceCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }
    else if(tenCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (twoCounter == 2 || threeCounter == 2 || fourCounter == 2
	 || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
	 || eightCounter == 2 || nineCounter == 2 || jackCounter == 2
	 || queenCounter == 2 || kingCounter == 2 || aceCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }
    else if(jackCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (twoCounter == 2 || threeCounter == 2 || fourCounter == 2
	 || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
	 || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
	 || queenCounter == 2 || kingCounter == 2 || aceCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }
    else if(queenCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (twoCounter == 2 || threeCounter == 2 || fourCounter == 2
	 || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
	 || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
	 || jackCounter == 2 || kingCounter == 2 || aceCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }
    else if(kingCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (twoCounter == 2 || threeCounter == 2 || fourCounter == 2
	 || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
	 || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
	 || jackCounter == 2 || queenCounter == 2 || aceCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }
    else if(aceCounter == 2)
    {
        if((twoCounter == 2 || threeCounter == 2 || fourCounter == 2
         || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
         || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
         || jackCounter == 2 || queenCounter == 2 || kingCounter == 2
         || aceCounter == 2)
         && (twoCounter == 2 || threeCounter == 2 || fourCounter == 2
	 || fiveCounter == 2 || sixCounter == 2 || sevenCounter == 2
	 || eightCounter == 2 || nineCounter == 2 || tenCounter == 2
	 || jackCounter == 2 || queenCounter == 2 || kingCounter == 2))
        {
            isComputerRoyalFlush = false;
            isComputerStraightFlush = false;
            isComputerFourOfAKind = false;
            isComputerFullHouse = false;
            isComputerFlush = false;
            isComputerStraight = false;
            isComputerThreeOfAKind = false;
            isComputerTwoPair = true;
            isComputerOnePair = false;
            isComputerNoHand = false;
        }
    }

    if(isHumanRoyalFlush == false && isHumanStraightFlush == false
    && isHumanFourOfAKind == false && isHumanFullHouse == false
    && isHumanFlush == false && isHumanStraight == false
    && isHumanThreeOfAKind == false)
    {
	if(twoHumanCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (threeHumanCounter == 2 || fourHumanCounter == 2 || fiveHumanCounter == 2
		|| sixHumanCounter == 2 || sevenHumanCounter == 2 || eightHumanCounter == 2
		|| nineHumanCounter == 2 || tenHumanCounter == 2 || nineHumanCounter == 2
		|| tenHumanCounter == 2 || jackHumanCounter == 2 || queenHumanCounter == 2
		|| kingHumanCounter == 2 || aceHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
	else if(threeHumanCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (twoHumanCounter == 2 || fourHumanCounter == 2 || fiveHumanCounter == 2
		|| sixHumanCounter == 2 || sevenHumanCounter == 2 || eightHumanCounter == 2
		|| nineHumanCounter == 2 || tenHumanCounter == 2 || jackHumanCounter == 2
		|| queenHumanCounter == 2 ||kingHumanCounter == 2 || aceHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
	else if(fourHumanCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (twoHumanCounter == 2 || threeHumanCounter == 2 || fiveHumanCounter == 2
		|| sixHumanCounter == 2 || sevenHumanCounter == 2 || eightHumanCounter == 2
		|| nineHumanCounter == 2 || tenHumanCounter == 2 || jackHumanCounter == 2
		|| queenHumanCounter == 2 || kingHumanCounter == 2 || aceHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
	else if(fiveHumanCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| sixHumanCounter == 2 || sevenHumanCounter == 2 || eightHumanCounter == 2
		|| nineHumanCounter == 2 || tenHumanCounter == 2 || jackHumanCounter == 2
		|| queenHumanCounter == 2 || kingHumanCounter == 2 || aceHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
	else if(sixHumanCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sevenHumanCounter == 2 || eightHumanCounter == 2
		|| nineHumanCounter == 2 || tenHumanCounter == 2 || jackHumanCounter == 2
		|| queenHumanCounter == 2 || kingHumanCounter == 2 || aceHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
	else if(sevenHumanCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || eightHumanCounter == 2
		|| nineHumanCounter == 2 || tenHumanCounter == 2 || jackHumanCounter == 2
		|| queenHumanCounter == 2 || kingHumanCounter == 2 || aceHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
	else if(eightHumanCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| nineHumanCounter == 2 || tenHumanCounter == 2 || jackHumanCounter == 2
		|| queenHumanCounter == 2 || kingHumanCounter == 2 || aceHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
	else if(nineHumanCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || tenHumanCounter == 2 || jackHumanCounter == 2
		|| queenHumanCounter == 2 || kingHumanCounter == 2 || aceHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
	else if(tenHumanCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || jackHumanCounter == 2
		|| queenHumanCounter == 2 || kingHumanCounter == 2 || aceHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
	else if(jackHumanCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| queenHumanCounter == 2 || kingHumanCounter == 2 || aceHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
	else if(queenHumanCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || kingHumanCounter == 2 || aceHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
	else if(kingCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || aceHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
	else if(aceHumanCounter == 2)
	{
		if((twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2
		|| aceHumanCounter == 2)
		&& (twoHumanCounter == 2 || threeHumanCounter == 2 || fourHumanCounter == 2
		|| fiveHumanCounter == 2 || sixHumanCounter == 2 || sevenHumanCounter == 2
		|| eightHumanCounter == 2 || nineHumanCounter == 2 || tenHumanCounter == 2
		|| jackHumanCounter == 2 || queenHumanCounter == 2 || kingHumanCounter == 2))
		{
		    isHumanRoyalFlush = false;
		    isHumanStraightFlush = false;
		    isHumanFourOfAKind = false;
		    isHumanFullHouse = false;
		    isHumanFlush = false;
		    isHumanStraight = false;
		    isHumanThreeOfAKind = false;
		    isHumanTwoPair = true;
		    isHumanOnePair = false;
		    isHumanNoHand = false;
		}
	}
    }
}
