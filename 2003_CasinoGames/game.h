//--------------------------------------------------
//game.h

#ifndef GAME_H
#define GAME_H
#include "headers.h"

typedef std::string cards_t;
typedef std::string name_t;
typedef int         money_t;
typedef int         maxsize_t;
typedef int         minsize_t;
typedef int         counter_t;
typedef int         temp_t;
typedef char        selection_t;
typedef bool        option_t;

const maxsize_t MAXCARDS = 52;

class CGame
{
public:
    //constructor destructor
    CGame();
    CGame(name_t, money_t);
    virtual ~CGame();

    //modifiers
    virtual money_t doMain     () = 0;
    virtual void clearHands    () = 0;
    virtual void countValues   () = 0;
    virtual void selectWinner  () = 0;
    virtual void calcPlayerMoney(std::string) = 0;
            void placeWager    ();
            void quit          ();

    //accessors
    virtual void displayGrid () const = 0;
            void clearScreen () const;
            void displayTitle() const;
            void showScreen  () const;
			void sleep() const;

    //public data
    option_t  isPlayAgain;
protected:
    name_t    playersName;
    money_t   playerMoney;
    money_t   wagerAmount;
    std::vector <cards_t> myCards;
    option_t  isQuit;
    option_t  isComputerHit;
    option_t  isHumanHit;
    option_t  isComputerStay;
    option_t  isHumanStay;
    option_t  isDraw;
    option_t  isHumanWin;
    option_t  isComputerWin;
    option_t  isFirstDeal;
    maxsize_t computerValueCount;
    maxsize_t humanValueCount;
};

#endif

//--------------------------------------------------