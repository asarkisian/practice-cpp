//--------------------------------------------------
//poker.h

#ifndef POKER_H
#define POKER_H
#include "game.h"

//const maxsize_t MAXSIZE  = 5;
const maxsize_t TWO      = 2;
const maxsize_t THREE    = 4;
const maxsize_t FOUR     = 8;
const maxsize_t FIVE     = 16;
const maxsize_t SIX      = 32;
const maxsize_t SEVEN    = 64;
const maxsize_t EIGHT    = 128;
const maxsize_t NINE     = 256;
const maxsize_t TEN      = 512;
const maxsize_t JACK     = 1024;
const maxsize_t QUEEN    = 2048;
const maxsize_t KING     = 4096;
const maxsize_t ACE      = 8192;

class CPoker : public CGame
{
public:
    //constructor
    CPoker();
    CPoker(name_t, money_t);
    virtual ~CPoker();

    //modifier
    money_t doMain();
    void    clearHands();
    void    dealCards(counter_t, counter_t);
    void    countValues();
    void    checkPatterns();
    void    checkRoyalFlush();
    void    checkStraightFlush();
    void    checkFourOfAKind();
    void    checkFullHouse();
    void    checkFlush();
    void    checkStraight();
    void    checkThreeOfAKind();
    void    checkTwoPair();
    void    checkOnePair();
    void    discardCards();
    void    selectWinner();
    void    calcPlayerMoney(std::string);

    //accessors
    void    displayGrid()const;

private:
    //private data
    std::vector <cards_t> playerHand;
    std::vector <cards_t> computerHand;
    cards_t usedCards;
    temp_t keepingCards;
    counter_t numberOfHumanDiscards;
    counter_t numberOfComputerDiscards;

    option_t isComputerRoyalFlush;
    option_t isComputerStraightFlush;
    option_t isComputerFourOfAKind;
    option_t isComputerFullHouse;
    option_t isComputerFlush;
    option_t isComputerStraight;
    option_t isComputerThreeOfAKind;
    option_t isComputerTwoPair;
    option_t isComputerOnePair;
    option_t isComputerNoHand;
    option_t isHumanRoyalFlush;
    option_t isHumanStraightFlush;
    option_t isHumanFourOfAKind;
    option_t isHumanFullHouse;
    option_t isHumanFlush;
    option_t isHumanStraight;
    option_t isHumanThreeOfAKind;
    option_t isHumanTwoPair;
    option_t isHumanOnePair;
    option_t isHumanNoHand;
    counter_t aceCounter;
    counter_t kingCounter;
    counter_t queenCounter;
    counter_t jackCounter;
    counter_t tenCounter;
    counter_t nineCounter;
    counter_t eightCounter;
    counter_t sevenCounter;
    counter_t sixCounter;
    counter_t fiveCounter;
    counter_t fourCounter;
    counter_t threeCounter;
    counter_t twoCounter;
    counter_t heartCounter;
    counter_t spadeCounter;
    counter_t clubCounter;
    counter_t diamondCounter;
    counter_t aceHumanCounter;
    counter_t kingHumanCounter;
    counter_t queenHumanCounter;
    counter_t jackHumanCounter;
    counter_t tenHumanCounter;
    counter_t nineHumanCounter;
    counter_t eightHumanCounter;
    counter_t sevenHumanCounter;
    counter_t sixHumanCounter;
    counter_t fiveHumanCounter;
    counter_t fourHumanCounter;
    counter_t threeHumanCounter;
    counter_t twoHumanCounter;
    counter_t heartHumanCounter;
    counter_t spadeHumanCounter;
    counter_t clubHumanCounter;
    counter_t diamondHumanCounter;
    counter_t computerWinDepth;
    counter_t humanWinDepth;
};

#endif

//--------------------------------------------------
