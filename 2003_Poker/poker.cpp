//--------------------------------------------------
//poker.cpp

#include "poker.h"
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

CPoker::CPoker()
:isPlayAgain(true),
usedCards("   "),
playersName(" "),
keepingCards(0),
numberOfHumanDiscards(0),
numberOfComputerDiscards(0),
isQuit(false),
isDraw(false),
isHumanWin(false),
isComputerWin(false),
isHumanHit(true),
isHumanStay(false),
isComputerHit(true),
isComputerStay(false),
isFirstDeal(true),
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
humanWinDepth(0),
computerValueCount(0),
humanValueCount(0),
playerMoney(50),
wagerAmount(0)
{
    myCards[0] = "2D ";
    myCards[1] = "2H ";
    myCards[2] = "2C ";
    myCards[3] = "2S ";

    myCards[4] = "3D ";
    myCards[5] = "3H ";
    myCards[6] = "3C ";
    myCards[7] = "3S ";

    myCards[8] = "4D ";
    myCards[9] = "4H ";
    myCards[10] = "4C ";
    myCards[11] = "4S ";

    myCards[12] = "5D ";
    myCards[13] = "5H ";
    myCards[14] = "5C ";
    myCards[15] = "5S ";

    myCards[16] = "6D ";
    myCards[17] = "6H ";
    myCards[18] = "6C ";
    myCards[19] = "6S ";

    myCards[20] = "7D ";
    myCards[21] = "7H ";
    myCards[22] = "7C ";
    myCards[23] = "7S ";

    myCards[24] = "8D ";
    myCards[25] = "8H ";
    myCards[26] = "8C ";
    myCards[27] = "8S ";

    myCards[28] = "9D ";
    myCards[29] = "9H ";
    myCards[30] = "9C ";
    myCards[31] = "9S ";

    myCards[32] = "10D";
    myCards[33] = "10H";
    myCards[34] = "10C";
    myCards[35] = "10S";

    myCards[36] = "JD ";
    myCards[37] = "JH ";
    myCards[38] = "JC ";
    myCards[39] = "JS ";

    myCards[40] = "QD ";
    myCards[41] = "QH ";
    myCards[42] = "QC ";
    myCards[43] = "QS ";

    myCards[44] = "KD ";
    myCards[45] = "KH ";
    myCards[46] = "KC ";
    myCards[47] = "KS ";

    myCards[48] = "AD ";
    myCards[49] = "AH ";
    myCards[50] = "AC ";
    myCards[51] = "AS ";

    for(int i = 0; i < MAXSIZE; ++i)
    {
        playerHand[i] = "   ";
        computerHand[i] = "   ";
    }
}


//--------------------------------------------------