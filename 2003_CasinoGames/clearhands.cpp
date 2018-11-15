#include "blackjack.h"
#include "poker.h"

//maxsize = 12

void CBlackjack::clearHands()
{
    for(int i = 0; i < 12; ++i)
    {
        playerHand[i] = "   ";
        computerHand[i] = "   ";
    }
}

//maxsize = 5

void CPoker::clearHands()
{
    for(int i = 0; i < 5; ++i)
    {
        playerHand[i] = "   ";
        computerHand[i] = "   ";
    }

    isComputerRoyalFlush = isComputerStraight = false;
    isComputerFourOfAKind = isComputerFullHouse = false;
    isComputerFlush = isComputerStraight = isComputerThreeOfAKind = false;
    isComputerTwoPair = isComputerOnePair = false;
    isComputerNoHand = true;

    isHumanRoyalFlush = isHumanStraight = false;
    isHumanFourOfAKind = isHumanFullHouse = false;
    isHumanFlush = isHumanStraight = isHumanThreeOfAKind = false;
    isHumanTwoPair = isHumanOnePair = false;
    isHumanNoHand = true;

    heartCounter = spadeCounter = clubCounter = diamondCounter = 0;
    aceCounter = kingCounter = queenCounter = jackCounter = 0;
    tenCounter = nineCounter = eightCounter = sevenCounter = 0;
    sixCounter = fiveCounter = fourCounter = threeCounter = twoCounter = 0;


    heartHumanCounter = spadeHumanCounter = clubHumanCounter = diamondHumanCounter = 0;
    aceHumanCounter = kingHumanCounter = queenHumanCounter = jackHumanCounter = 0;
    tenHumanCounter = nineHumanCounter = eightHumanCounter = sevenHumanCounter = 0;
    sixHumanCounter = fiveHumanCounter = fourHumanCounter = threeHumanCounter = twoHumanCounter = 0;
}
