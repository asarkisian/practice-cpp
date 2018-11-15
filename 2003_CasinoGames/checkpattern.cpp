#include "poker.h"

void CPoker::checkPatterns()
{
    checkRoyalFlush();
    if(isComputerRoyalFlush == true)
    {
        isComputerStay = true;
        isComputerHit = false;
	return;
    }

    checkStraightFlush();
    if(isComputerStraightFlush == true)
    {
	isComputerStay = true;
	isComputerHit = false;
        return;
    }

    checkFourOfAKind();
    if(isComputerFourOfAKind == true)
    {
	isComputerStay = true;
	isComputerHit = false;
        return;
    }

    checkFullHouse();
    if(isComputerFullHouse == true)
    {
	isComputerStay = true;
	isComputerHit = false;
        return;
    }

    checkFlush();
    if(isComputerFlush == true)
    {
	isComputerStay = true;
        isComputerHit = false;
        return;
    }

    checkStraight();
    if(isComputerStraight == true)
    {
	isComputerStay = true;
	isComputerHit = false;
        return;
    }

    checkThreeOfAKind();
    if(isComputerThreeOfAKind == true)
    {
        return;
    }

    checkTwoPair();
    if(isComputerTwoPair == true)
    {
        return;
    }

    checkOnePair();
    if(isComputerOnePair == true)
    {
        return;
    }

    //else
    isComputerRoyalFlush = false;
    isComputerStraightFlush = false;
    isComputerFourOfAKind = false;
    isComputerFullHouse = false;
    isComputerFlush = false;
    isComputerStraight = false;
    isComputerThreeOfAKind = false;
    isComputerTwoPair = false;
    isComputerOnePair = false;
    isComputerNoHand = true;

    if(isHumanRoyalFlush == false && isHumanStraightFlush == false
    && isHumanFourOfAKind == false && isHumanFullHouse == false
    && isHumanFlush == false && isHumanStraight == false
    && isHumanThreeOfAKind == false && isHumanTwoPair == false
    && isHumanOnePair == false)
    {
    	isHumanRoyalFlush = false;
    	isHumanStraightFlush = false;
    	isHumanFourOfAKind = false;
 	isHumanFullHouse = false;
    	isHumanFlush = false;
    	isHumanStraight = false;
    	isHumanThreeOfAKind = false;
    	isHumanTwoPair = false;
    	isHumanOnePair = false;
    	isHumanNoHand = true;
    }
}