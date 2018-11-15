//--------------------------------------------------
//poker.h

#ifndef POKER_H
#define POKER_H
#include <string>

const int MAXCARDS = 52;
const int MAXSIZE  = 5;
const int TWO      = 2;
const int THREE    = 4;
const int FOUR     = 8;
const int FIVE     = 16;
const int SIX      = 32;
const int SEVEN    = 64;
const int EIGHT    = 128;
const int NINE     = 256;
const int TEN      = 512;
const int JACK     = 1024;
const int QUEEN    = 2048;
const int KING     = 4096;
const int ACE      = 8192;

class CPoker
{
public:
    //constructor
    CPoker();

    //modifier
    void doMain();
    void clearHands();
    void dealCards(int, int);
    void countValues();
    void checkPatterns();
    void checkRoyalFlush();
    void checkStraightFlush();
    void checkFourOfAKind();
    void checkFullHouse();
    void checkFlush();
    void checkStraight();
    void checkThreeOfAKind();
    void checkTwoPair();
    void checkOnePair();
    void discardCards();
    void selectWinner();
    void quit();
    void calcPlayerMoney(std::string);
    void placeWager();
    void getPlayersName();

    //accessors
    void showScreen()const;
    void clearScreen()const;
    void displayTitle()const;
    void displayGrid()const;

    //public data
    bool isPlayAgain;
private:
    //private data
    std::string myCards[MAXCARDS];
    std::string playerHand[MAXSIZE];
    std::string computerHand[MAXSIZE];
    std::string usedCards;
    std::string playersName;
    int keepingCards;
    int numberOfHumanDiscards;
    int numberOfComputerDiscards;
    bool isQuit;
    bool isDraw;
    bool isHumanWin;
    bool isComputerWin;
    bool isHumanHit;
    bool isHumanStay;
    bool isComputerHit;
    bool isComputerStay;
    bool isFirstDeal;
    bool isComputerRoyalFlush;
    bool isComputerStraightFlush;
    bool isComputerFourOfAKind;
    bool isComputerFullHouse;
    bool isComputerFlush;
    bool isComputerStraight;
    bool isComputerThreeOfAKind;
    bool isComputerTwoPair;
    bool isComputerOnePair;
    bool isComputerNoHand;
    bool isHumanRoyalFlush;
    bool isHumanStraightFlush;
    bool isHumanFourOfAKind;
    bool isHumanFullHouse;
    bool isHumanFlush;
    bool isHumanStraight;
    bool isHumanThreeOfAKind;
    bool isHumanTwoPair;
    bool isHumanOnePair;
    bool isHumanNoHand;
    int aceCounter;
    int kingCounter;
    int queenCounter;
    int jackCounter;
    int tenCounter;
    int nineCounter;
    int eightCounter;
    int sevenCounter;
    int sixCounter;
    int fiveCounter;
    int fourCounter;
    int threeCounter;
    int twoCounter;
    int heartCounter;
    int spadeCounter;
    int clubCounter;
    int diamondCounter;
    int aceHumanCounter;
    int kingHumanCounter;
    int queenHumanCounter;
    int jackHumanCounter;
    int tenHumanCounter;
    int nineHumanCounter;
    int eightHumanCounter;
    int sevenHumanCounter;
    int sixHumanCounter;
    int fiveHumanCounter;
    int fourHumanCounter;
    int threeHumanCounter;
    int twoHumanCounter;
    int heartHumanCounter;
    int spadeHumanCounter;
    int clubHumanCounter;
    int diamondHumanCounter;
    int computerWinDepth;
    int humanWinDepth;
    int computerValueCount;
    int humanValueCount;
    int playerMoney;
    int wagerAmount;
};

#endif

//--------------------------------------------------
