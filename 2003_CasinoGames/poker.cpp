//--------------------------------------------------
//poker.cpp

#include "poker.h"
using std::cout;
using std::endl;
using std::cin;

CPoker::CPoker()
{}

CPoker::CPoker(name_t n, money_t t)
:CGame(n, t),
playerHand(5),
computerHand(5),
usedCards("   "),
keepingCards(0),
numberOfHumanDiscards(0),
numberOfComputerDiscards(0),
isComputerRoyalFlush(false),
isComputerStraightFlush(false),
isComputerFourOfAKind(false),
isComputerFullHouse(false),
isComputerFlush(false),
isComputerStraight(false),
isComputerThreeOfAKind(false),
isComputerTwoPair(false),
isComputerOnePair(false),
isComputerNoHand(true),
isHumanRoyalFlush(false),
isHumanStraightFlush(false),
isHumanFourOfAKind(false),
isHumanFullHouse(false),
isHumanFlush(false),
isHumanStraight(false),
isHumanThreeOfAKind(false),
isHumanTwoPair(false),
isHumanOnePair(false),
isHumanNoHand(true),
aceCounter(0),
kingCounter(0),
queenCounter(0),
jackCounter(0),
tenCounter(0),
nineCounter(0),
eightCounter(0),
sevenCounter(0),
sixCounter(0),
fiveCounter(0),
fourCounter(0),
threeCounter(0),
twoCounter(0),
heartCounter(0),
spadeCounter(0),
clubCounter(0),
diamondCounter(0),
aceHumanCounter(0),
kingHumanCounter(0),
queenHumanCounter(0),
jackHumanCounter(0),
tenHumanCounter(0),
nineHumanCounter(0),
eightHumanCounter(0),
sevenHumanCounter(0),
sixHumanCounter(0),
fiveHumanCounter(0),
fourHumanCounter(0),
threeHumanCounter(0),
twoHumanCounter(0),
heartHumanCounter(0),
spadeHumanCounter(0),
clubHumanCounter(0),
computerWinDepth(0),
humanWinDepth(0)
{
    for(counter_t i = 0; i < 5; ++i)
    {
        playerHand[i] = "   ";
        computerHand[i] = "   ";
    }
}

CPoker::~CPoker()
{}


//--------------------------------------------------
